#ifndef ITEM_HPP
#define ITEM_HPP
#include<iostream>
#include"vector3d.hpp"
#include"const.hpp"

class Item{
    protected:
        ufloat m0;
        Vector3d x;
        Vector3d v;
    public:
        Item(const ufloat,
            const Vector3d=Vector3d(),
            const Vector3d=Vector3d());
        Vector3d getPosition() const;
        Vector3d getSpeed() const;
        ufloat getEdge() const;
        void setStatus(const Vector3d=Vector3d(), const ufloat=1);
        ufloat operator + (const ufloat) const;
        ufloat operator + (const Item) const;
        ufloat operator - (const ufloat) const;
        ufloat operator - (const Item) const;
        ufloat operator * (const ufloat) const;
        ufloat operator * (const Item) const;
        ufloat operator / (const ufloat) const;
        ufloat operator / (const Item) const;
        ufloat operator () () const;
};

#endif
