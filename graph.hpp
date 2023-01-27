#ifndef GRAPH_HPP
#define GRAPH_HPP
#include<iostream>
#include"item.hpp"
#include"force.hpp"
#include"display.hpp"

class Graph{
    private:
        Item** item;
        Force** force;
        Display** display;
        int _size;
    public:
        Graph(const int);
        ~Graph();
        Item* getItem(const int);
        void setItem(const int, Item*);
        Force* getForce(const int, const int);
        void setForce(const int, const int, Force*);
        Display* getDisplay(const int);
        void setDisplay(const int, Display*);
        void setStatusAll();
        void setForceAll();
        int getSize();
};

#endif
