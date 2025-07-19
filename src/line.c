#include <stdbool.h>

#include "../include/line.h"
#include "../include/xyz.h"


double line_getLength(const void* line)
{
    Line* l = (Line*)line;
    return dist(l->endPoints, l->endPoints + 3);
}


bool line_isBound(const void* line)
{
    Line* l = (Line*)line;
    return l->isBound;
}


bool line_getEndPoint(const void* line, const short index, double* endPoint)
{
    if (index != 0 && index != 1)
    {
        return false;
    }

    Line* l = (Line*)line;
    endPoint[0] = l->endPoints[0 + 3*index];
    endPoint[1] = l->endPoints[1 + 3*index];
    endPoint[2] = l->endPoints[2 + 3*index];

    return true;
}


void line_eval(const void* line, const double param, double* eval)
{
    Line* l = (Line*)line;
    eval[0] = l->endPoints[0] + param * l->direction[0];
    eval[1] = l->endPoints[1] + param * l->direction[1];
    eval[2] = l->endPoints[2] + param * l->direction[2];
}


bool line_createBound(const double* end0, const double* end1, Line* line)
{
    if (dist(end0, end1) < eps)
    {
        return false;
    }


    line->endPoints[0] = end0[0];
    line->endPoints[1] = end0[1];
    line->endPoints[2] = end0[2];
    line->endPoints[3] = end1[0];
    line->endPoints[4] = end1[1];
    line->endPoints[5] = end1[2];

    line->direction[0] = end1[0] - end0[0];
    line->direction[1] = end1[1] - end0[1];
    line->direction[2] = end1[2] - end0[2];
    norm(line->direction, line->direction);

    line->isBound = true;

    return true;
}


bool line_createUnbound(const double* origin, const double* direction, Line* line)
{
    if (dist(direction, zero) < eps)
    {
        return false;
    }


    line->endPoints[0] = origin[0];
    line->endPoints[1] = origin[1];
    line->endPoints[2] = origin[2];
    line->endPoints[3] = 0;
    line->endPoints[4] = 0;
    line->endPoints[5] = 0;

    line->direction[0] = direction[0];
    line->direction[1] = direction[1];
    line->direction[2] = direction[2];
    norm(line->direction, line->direction);

    line->isBound = false;

    return true;
}
