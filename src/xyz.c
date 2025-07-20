#include <stdbool.h>
#include <math.h>

#include "../include/xyz.h"

const double zero[3]  = {0,0,0};
const double axisX[3] = {1,0,0};
const double axisY[3] = {0,1,0};
const double axisZ[3] = {0,0,1};


inline void xyz_plus(const double* p1, const double* p2, double* res)
{
    res[0] = p1[0] + p2[0];
    res[1] = p1[1] + p2[1];
    res[2] = p1[2] + p2[2];
}


inline void xyz_minus(const double* p1, const double* p2, double* res)
{
    res[0] = p1[0] - p2[0];
    res[1] = p1[1] - p2[1];
    res[2] = p1[2] - p2[2];
}


inline void xyz_scale(const double* p, const double factor, double* res)
{
    res[0] = p[0] * factor;
    res[1] = p[1] * factor;
    res[2] = p[2] * factor;
}


inline double dist_sq(const double* p1, const double* p2)
{
    return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]) + (p2[2]-p1[2])*(p2[2]-p1[2]);
}


double dist(const double* p1, const double* p2)
{
    return sqrt(dist_sq(p1, p2));
}


inline double dot(const double* p1, const double* p2)
{
    return p1[0]*p2[0] + p1[1]*p2[1] + p1[2]*p2[2];
}


void norm(const double* v, double* norm)
{
    double length = dist(zero, v);

    norm[0] = v[0] / length;
    norm[1] = v[1] / length;
    norm[2] = v[2] / length;
}
