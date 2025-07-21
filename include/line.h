#ifndef LINE
#define LINE


#include <stdbool.h>

#include "base_curve.h"

typedef struct Line{
    double endPoints[6];
    double direction[3];
    bool isBound;
} Line;


double line_getLength(const void* line);
bool line_isBound(const void* line);
//Return value is pointer to endPoint, for chaining. Will be null if index is out of range [0, 1].
double* line_getEndPoint(const void* line, const short index, double* endPoint);
double* line_compDeriv(const void* line, const double param, double* deriv);
double* line_eval(const void* line, const double param, double* eval);
paramDist line_project(const void* line, const double* point, double* proj);

bool line_createBound(const double* end0, const double* end1, Line* line);
bool line_createUnbound(const double* orign, const double* direction, Line* line);


extern const Curve line_curve;


#endif  //LINE
