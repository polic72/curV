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


    return 0;
}
