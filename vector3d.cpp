#include<iostream>
#include<cmath>
#include"const.hpp"
#include"vector3d.hpp"
using namespace std;

Vector3d::Vector3d(const ufloat x_in, const ufloat y_in, const ufloat z_in):
    x(x_in), y(y_in), z(z_in){};

ufloat& Vector3d::operator[](const int8_t n){
    return (n==0)? x: (n==1)? y: z;
};
ufloat Vector3d::operator()(const int8_t n) const{
    return (n==0)? x: (n==1)? y: z;
};

bool Vector3d::isnan() const{
    return std::isnan(x) and std::isnan(y) and std::isnan(z);
};

Vector3d Vector3d::operator + (Vector3d v) const{
    Vector3d v0=Vector3d(x,y,z);
    v0[0]+=v(0);
    v0[1]+=v(1);
    v0[2]+=v(2);
    return v0;
};

Vector3d Vector3d::operator - (Vector3d v) const{
    Vector3d v0=Vector3d(x,y,z);
    v0[0]-=v(0);
    v0[1]-=v(1);
    v0[2]-=v(2);
    return v0;
};

Vector3d Vector3d::operator * (const ufloat c) const{
    Vector3d v0=Vector3d(x,y,z);
    v0[0]*=c;
    v0[1]*=c;
    v0[2]*=c;
    return v0;
};

Vector3d Vector3d::operator / (const ufloat c) const{
    Vector3d v0=Vector3d(x,y,z);
    v0[0]/=c;
    v0[1]/=c;
    v0[2]/=c;
    return v0;
};

Vector3d Vector3d::operator * (Vector3d v) const{
    Vector3d v0=Vector3d(x,y,z);
    v0[0]*=v(0);
    v0[1]*=v(1);
    v0[2]*=v(2);
    return v0;
};
