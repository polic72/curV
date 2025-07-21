#ifndef ARC
#define ARC


#include <stdbool.h>

#include "base_curve.h"

typedef struct Arc{
    double center[3];
    double normal[3];
    //Encodes the radius too (as the magnitude).
    double x_axis[3];
    //Will both be NaN if unbounded.
    double endParam;
    bool isBound;
} Arc;


double arc_getLength(const void* arc);
bool arc_isBound(const void* arc);
double* arc_getEndPoint(const void* arc, const short index, double* endPoint);
double* arc_compDeriv(const void* arc, const double param, double* deriv);
double* arc_eval(const void* arc, const double param, double* eval);
paramDist arc_project(const void* arc, const double* point, double* proj);

bool arc_createBound(const double* end0, const double* end1, Arc* arc);
bool arc_createUnbound(const double* orign, const double* direction, Arc* arc);
double arc_getRadius(const void* arc);


extern const Curve arc_curve;


#endif  //ARC
