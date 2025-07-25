#include <stdio.h>

#include "../include/base_curve.h"
#include "../include/line.h"
#include "../include/xyz.h"


int main()
{
    Line line;

    double p1[] = {0,0,0};
    double p2[] = {2,0,0};

    line_createBound(p1, p2, &line);


    printf("length = %f\n", line_getLength(&line));

    double eval[3];
    line_eval(&line, 0.5, eval);
    printf("eval(0.5) = (%f, %f, %f)\n", eval[0], eval[1], eval[2]);


    double third[] = {1,1,0};
    double proj[3];
    paramDist pd = line_project(&line, third, proj);
    printf("param = %f, dist = %f, project((1, 1, 0)) = (%f, %f, %f)\n", pd.param, pd.distance, proj[0], proj[1], proj[2]);

    double third_other[] = {1,19,0};
    double proj_other[3];
    paramDist pd_other = line_project(&line, third_other, proj_other);
    printf("param = %f, dist = %f, project((1, 19, 0)) = (%f, %f, %f)\n", pd_other.param, pd_other.distance, proj_other[0], proj_other[1], proj_other[2]);


    double v1[] = {1,0,0};
    double v2[] = {0,1,0};
    double norm[] = {0,0,-1};
    printf("angle((%f, %f, %f), (%f, %f, %f)) = %f\n", v1[0], v1[1], v1[2], v2[0], v2[1], v2[2], angle(v1, v2));
    printf("angle_plane((%f, %f, %f), (%f, %f, %f), (%f, %f, %f)) = %f\n", v1[0], v1[1], v1[2], v2[0], v2[1], v2[2], norm[0], norm[1], norm[2], angle_plane(v1, v2, norm));


    return 0;
}
