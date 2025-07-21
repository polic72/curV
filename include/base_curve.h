#ifndef BASE_CURVE
#define BASE_CURVE


#include <stdbool.h>

typedef struct paramDist{
    double param;
    double distance;
} paramDist;

//Need to think of ways to handle raw vs normalized parameters.
typedef struct Curve{
    double (*getLength)(const void*);
    bool (*isBound)(const void*);

    //Return value is pointer to endPoint, for chaining. Will be null if index is out of range [0, 1].
    double* (*getEndPoint)(const void*, const short index, double* endPoint);
    //Return value is pointer to point, for chaining.
    double* (*compDeriv)(const void*, const double param, double* deriv);
    //Return value is pointer to point, for chaining.
    double* (*eval)(const void*, const double param, double* eval);
    paramDist (*project)(const void*, const double* point, double* proj);
} Curve;


extern const double eps;


#endif  //BASE_CURVE
