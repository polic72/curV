#ifndef BASE_CURVE
#define BASE_CURVE


#include <stdbool.h>

typedef struct {
    double param;
    double distance;
} paramDist;

//Need to think of ways to handle raw vs normalized parameters.
typedef struct {
    double (*getLength)(const void*);
    bool (*isBound)(const void*);

    bool (*getEndPoint)(const void*, const short index, double* endPoint);
    //void (*compDeriv)(void*, double, double*);
    void (*eval)(const void*, const double param, double* point);
    paramDist (*project)(const void*, const double* point, double* proj);
} Curve;


extern const double eps;


#endif  //BASE_CURVE
