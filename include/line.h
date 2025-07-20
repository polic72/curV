#ifndef LINE
#define LINE


#include <stdbool.h>

#include "base_curve.h"

typedef struct {
    double endPoints[6];
    double direction[3];
    bool isBound;
} Line;


//Curve line_cuve = {line_getLength, line_isBound, line_getEndPoint, line_eval};

double line_getLength(const void* line);
bool line_isBound(const void* line);
bool line_getEndPoint(const void* line, const short index, double* endPoint);
void line_eval(const void* line, const double param, double* point);
paramDist line_project(const void* line, const double* point, double* proj);

bool line_createBound(const double* end0, const double* end1, Line* line);
bool line_createUnbound(const double* orign, const double* direction, Line* line);


#endif  //LINE
