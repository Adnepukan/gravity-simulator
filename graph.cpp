#include<iostream>
#include"graph.hpp"
#include"item.hpp"
#include"force.hpp"
#include"force-gravity.hpp"
using namespace std;

Graph::Graph(const int _size_in):
    _size(_size_in),
    item(new Item*[_size_in]),
    force(new Force*[_size_in*(_size_in-1)/2]),
    display(new Display*[_size_in]){
    for(int i=0; i<_size_in; ++i)
        item[i]=NULL;
    for(int i=0; i<_size_in*(_size_in-1)/2; ++i)
        force[i]=NULL;
    for(int i=0; i<_size_in; ++i)
        display[i]=NULL;
};

Graph::~Graph(){
    for(int i=0; i<_size; ++i)
        delete item[i];
    for(int i=0; i<_size*(_size-1)/2; ++i)
        delete force[i];
    for(int i=0; i<_size; ++i)
        delete display[i];
    delete [] item;
    delete [] force;
    delete [] display;
};

Item* Graph::getItem(const int i){
    return (i>=0 && i<_size) ? item[i] : NULL;
};

void Graph::setItem(const int i, Item* item_in){
    if(i>=0 && i<_size)
        item[i]=item_in;
};

Force* Graph::getForce(const int i, const int j){
    int more=(i>j)? i: j;
    int less=(i>j)? j: i;
    if(more>=_size || less<0 || more==less)
        return NULL;
    return force[(more-1)*more/2+less];
};

void Graph::setForce(const int i, const int j, Force* f){
    int more=(i>j)? i: j;
    int less=(i>j)? j: i;
    if(more>=_size || less<0 || more==less)
        return;
    force[(more-1)*more/2+less]=f;
};

Display* Graph::getDisplay(const int i){
    return (i>=0 && i<_size) ? display[i] : NULL;
};

void Graph::setDisplay(const int i, Display* display_in){
    if(i>=0 && i<_size)
        display[i]=display_in;
};

void Graph::setStatusAll(){
    Vector3d f;
    for(int i=0; i<_size; ++i){
        f[0]=0;
        f[1]=0;
        f[2]=0;
        for(int j=0; j<i; ++j)
            f=f-(*getForce(i,j))();
        for(int j=i+1; j<_size; ++j)
            f=f+(*getForce(i,j))();
        item[i]->setStatus(f/(*item[i])(), 10000);
    }
};

void Graph::setForceAll(){
    for(int i=0; i<_size*(_size-1)/2; ++i)
        ((ForceGravity*)(force[i]))->setForce();
};

int Graph::getSize(){return _size;};
