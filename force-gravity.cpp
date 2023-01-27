#include<iostream>
#include<cmath>
#include"force.hpp"
#include"force-gravity.hpp"
#include"item-circle.hpp"
#include"const.hpp"
using namespace std;

ForceGravity::ForceGravity(Item* i1, Item* i2):
    Force(i1, i2){};

void ForceGravity::setForce(){
    Vector3d d=item2->getPosition()-item1->getPosition();
    Vector3d d2=d*d;
    ufloat gabs=(*item1)*(*item2)*G_GRAVITY*pow(d2(0)+d2(1)+d2(2), -1.5);
    f=d*gabs;
};
