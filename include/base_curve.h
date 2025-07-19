#ifndef BASE_CURVE
#define BASE_CURVE


#include <stdbool.h>

//Need to think of ways to handle raw vs normalized parameters.
typedef struct {
    double (*getLength)(const void*);
    bool (*isBound)(const void*);

    bool (*getEndPoint)(const void*, const short, double*);
    //void (*compDeriv)(void*, double, double*);
    void (*eval)(const void*, const double, double*);
} Curve;


extern const double eps;


#endif  //BASE_CURVE
