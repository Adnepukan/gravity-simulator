#include<iostream>
#include"const.hpp"
#include"force.hpp"
using namespace std;

Force::Force(Item* i1, Item* i2):
    item1(i1), item2(i2){};
Item* Force::getSub(){return item2;};
Item* Force::getObj(){return item1;};
void Force::setForce(){f=Vector3d();};
Vector3d Force::operator () () const{return f;};
