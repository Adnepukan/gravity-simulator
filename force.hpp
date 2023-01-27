#ifndef FORCE_HPP
#define FORCE_HPP
#include<iostream>
#include"item.hpp"
#include"const.hpp"
#include"vector3d.hpp"

class Force{
    protected:
        Vector3d f;
        Item* item1;
        Item* item2;
    public:
        Force(Item*, Item*);
        Force(Item&)=delete;
        void setForce();
        Vector3d operator () () const;
        Item* getSub();
        Item* getObj();
};
#endif
