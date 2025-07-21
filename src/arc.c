#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>

#include "../include/arc.h"
#include "../include/xyz.h"


double arc_getLength(const void* arc)
{
    Arc* a = (Arc*)arc;
    double radius = arc_getRadius(a);

    if (!a->isBound)
        return 2 * M_PI * radius;

    return a->endParam * radius;
}


inline bool arc_isBound(const void* arc)
{
    Arc* a = (Arc*)arc;
    return a->isBound;
}


double* arc_getEndPoint(const void* arc, const short index, double* endPoint)
{
    Arc* a = (Arc*)arc;
    if (!a->isBound)
    {
        return NULL;
    }

    //Only needed in case 1, but C is annoying so this has to be here...
    switch (index)
    {
        case 0:
            return xyz_plus(a->x_axis, a->center, endPoint);

        case 1:
            {
                double norm_cross_xAxis[3];
                cross(a->normal, a->x_axis, norm_cross_xAxis);

                xyz_plus(a->x_axis, xyz_scale(norm_cross_xAxis, sin(a->endParam), endPoint), endPoint);

                double norm_cross_normCrossXAxis[3];
                return xyz_plus(xyz_scale(cross(a->normal, norm_cross_xAxis, norm_cross_normCrossXAxis), 1 - cos(a->endParam), norm_cross_normCrossXAxis), endPoint, endPoint);
                break;
            }

        default:
            return NULL;
    }
}


//double* arc_compDeriv(const void* arc, const double param, double* deriv)
//{
//    Arc* a = (Arc*)arc;
//}
//
//
//double* arc_eval(const void* arc, const double param, double* eval)
//{
//    Arc* a = (Arc*)arc;
//}
//
//
//paramDist arc_project(const void* arc, const double* point, double* proj)
//{
//    Arc* a = (Arc*)arc;
//}


inline double arc_getRadius(const void* arc)
{
    Arc* a = (Arc*)arc;
    return mag(a->x_axis);
}


const Curve arc_curve = {arc_getLength, arc_isBound, arc_getEndPoint, arc_compDeriv, arc_eval, arc_project};
