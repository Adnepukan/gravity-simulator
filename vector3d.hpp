#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include<iostream>
#include"const.hpp"

class Vector3d{
    private:
        ufloat x, y, z;
    public:
        Vector3d(const ufloat=0, const ufloat=0, const ufloat=0);
        ufloat& operator[](const int8_t);
        ufloat operator()(const int8_t) const;
        bool isnan() const;
        Vector3d operator + (Vector3d) const;
        Vector3d operator - (Vector3d) const;
        Vector3d operator * (const ufloat) const;
        Vector3d operator * (Vector3d) const;
        Vector3d operator / (const ufloat) const;
};
#endif
