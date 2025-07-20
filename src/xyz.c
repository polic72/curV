#include <stdbool.h>
#include <math.h>

#include "../include/xyz.h"

const double zero[3]  = {0,0,0};
const double axisX[3] = {1,0,0};
const double axisY[3] = {0,1,0};
const double axisZ[3] = {0,0,1};


inline double* xyz_plus(const double* p1, const double* p2, double* res)
{
    res[0] = p1[0] + p2[0];
    res[1] = p1[1] + p2[1];
    res[2] = p1[2] + p2[2];
    return res;
}


inline double* xyz_minus(const double* p1, const double* p2, double* res)
{
    res[0] = p1[0] - p2[0];
    res[1] = p1[1] - p2[1];
    res[2] = p1[2] - p2[2];
    return res;
}


inline double* xyz_scale(const double* v, const double factor, double* res)
{
    res[0] = v[0] * factor;
    res[1] = v[1] * factor;
    res[2] = v[2] * factor;
    return res;
}


inline double dist_sq(const double* p1, const double* p2)
{
    return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]) + (p2[2]-p1[2])*(p2[2]-p1[2]);
}


inline double dist(const double* p1, const double* p2)
{
    return sqrt(dist_sq(p1, p2));
}


inline double mag(const double* v)
{
    return dist(v, zero);
}


inline double dot(const double* v1, const double* v2)
{
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}


inline double* cross(const double* v1, const double* v2, double* res)
{
    res[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    res[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
    res[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
    return res;
}


double* norm(const double* v, double* res)
{
    double magnitude = mag(v);

    res[0] = v[0] / magnitude;
    res[1] = v[1] / magnitude;
    res[2] = v[2] / magnitude;
    return res;
}


inline double* proj_norm(const double* v, const double* base, double* res)
{
    xyz_scale(base, dot(v, base), res);
    return res;
}


inline double* proj(const double* v, const double* base, double* res)
{
    xyz_scale(base, dot(v, base) / (mag(base) * mag(base)), res);
    return res;
}


inline double angle_norm(const double* v1, const double* v2)
{
    return acos(dot(v1, v2));
}


inline double angle(const double* v1, const double* v2)
{
    return acos(dot(v1, v2) / (mag(v1) * mag(v2)));
}


double angle_plane(const double* v1, const double* v2, const double* normal)
{
    //This process was inspired by:
    //https://stackoverflow.com/questions/5188561/signed-angle-between-two-3d-vectors-with-same-origin-within-the-same-plane#answer-33920320
    //Thanks Adrian!

    double cross1[3];
    double cross2[3];
    norm(cross(v1, normal, cross1), cross1);
    norm(cross(v2, normal, cross2), cross2);

    double crosscross[3];
    cross(cross1, cross2, crosscross);

    return atan2(dot(crosscross, normal), dot(cross1, cross2));
}
