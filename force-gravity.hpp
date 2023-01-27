#ifndef FORCE_GRAVITY_HPP
#define FORCE_GRAVITY_HPP
#include<iostream>
#include"item.hpp"
#include"force.hpp"
#include"const.hpp"

class ForceGravity: public Force{
    public:
        ForceGravity(Item*, Item*);
        ForceGravity(ForceGravity&)=delete;
        void setForce();
};
#endif
