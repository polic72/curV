#ifndef XYZ
#define XYZ


extern const double zero[3];  // {0,0,0};
extern const double axisX[3]; // {1,0,0};
extern const double axisY[3]; // {0,1,0};
extern const double axisZ[3]; // {0,0,1};

//Return value is pointer to res, for chaining.
double* xyz_plus(const double* p1, const double* p2, double* res);
//Return value is pointer to res, for chaining.
double* xyz_minus(const double* p1, const double* p2, double* res);
//Return value is pointer to res, for chaining.
double* xyz_scale(const double* v, const double factor, double* res);

double dist_sq(const double* p1, const double* p2);
double dist(const double* p1, const double* p2);
double mag(const double* v);

double dot(const double* v1, const double* v2);
//Return value is pointer to res, for chaining.
double* cross(const double* v1, const double* v2, double* res);

//Return value is pointer to res, for chaining.
double* norm(const double* v, double* res);

//Only relevant if base is normalized.
//Return value is pointer to res, for chaining.
double* proj_norm(const double* v, const double* base, double* res);
//Return value is pointer to res, for chaining.
double* proj(const double* v, const double* base, double* res);

double angle_norm(const double* v1, const double* v2);
double angle(const double* v1, const double* v2);
//double angleNorm_plane(const double* v1, const double* v2, const double* norm);

//The given normal vector should be normalized.
double angle_plane(const double* v1, const double* v2, const double* normal);


#endif  //XYZ
