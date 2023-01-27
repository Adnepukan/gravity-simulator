#include<iostream>
#include"vector3d.hpp"
#include"const.hpp"
#include"item.hpp"
using namespace std;

Item::Item(const ufloat m0_in,
    const Vector3d x0_in, const Vector3d v0_in):
    m0(m0_in), x(x0_in), v(v0_in){};

Vector3d Item::getPosition() const{return x;};
Vector3d Item::getSpeed() const{return v;};
ufloat Item::getEdge() const{return 0;};

void Item::setStatus(const Vector3d a, const ufloat time){
    x=x+v*time;
    v=v+a*time;
};

ufloat Item::operator + (const ufloat c) const{return m0+c;};
ufloat Item::operator - (const ufloat c) const{return m0-c;};
ufloat Item::operator * (const ufloat c) const{return m0*c;};
ufloat Item::operator / (const ufloat c) const{return m0/c;};
ufloat Item::operator + (const Item i) const{return m0+i();};
ufloat Item::operator - (const Item i) const{return m0-i();};
ufloat Item::operator * (const Item i) const{return m0*i();};
ufloat Item::operator / (const Item i) const{return m0/i();};
ufloat Item::operator () () const{return m0;};
