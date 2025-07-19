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

double line_getLength(const void*);
bool line_isBound(const void*);
bool line_getEndPoint(const void*, const short, double*);
void line_eval(const void*, const double, double*);

bool line_createBound(const double* end0, const double* end1, Line* line);
bool line_createUnbound(const double* orign, const double* direction, Line* line);


#endif  //LINE
