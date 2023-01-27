#ifndef ITEM_CIRCLE_HPP
#define ITEM_CIRCLE_HPP
#include<iostream>
#include"item.hpp"

class ItemCircle: public Item{
    protected:
        ufloat r0;
    public:
        ItemCircle(const ufloat m0_in,
            const Vector3d=Vector3d(),
            const Vector3d=Vector3d(),
            const ufloat=0);
        ItemCircle(ItemCircle&)=delete;
        Vector3d getPosition();
        Vector3d getSpeed();
        ufloat getEdge();
};
#endif
