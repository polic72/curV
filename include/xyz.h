#ifndef XYZ
#define XYZ


extern const double zero[3];  // {0,0,0};
extern const double axisX[3]; // {1,0,0};
extern const double axisY[3]; // {0,1,0};
extern const double axisZ[3]; // {0,0,1};
//static const double zero[3]  = {0,0,0};
//static const double axisX[3] = {1,0,0};
//static const double axisY[3] = {0,1,0};
//static const double axisZ[3] = {0,0,1};

double dist_sq(const double* p1, const double* p2);
double dist(const double* p1, const double* p2);

double dot(const double* p1, const double* p2);

void norm(const double* v, double* norm);


#endif  //XYZ
