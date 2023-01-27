#include<iostream>
#include"item.hpp"
#include"item-circle.hpp"
using namespace std;

ItemCircle::ItemCircle(const ufloat m0_in,
    const Vector3d x0_in,
    const Vector3d v0_in,
    const ufloat r0_in):
    Item(m0_in, x0_in, v0_in), r0(r0_in){};

Vector3d ItemCircle::getPosition(){return x;};
Vector3d ItemCircle::getSpeed(){return v;};
ufloat ItemCircle::getEdge(){return r0;}
