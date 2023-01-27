#include<iostream>
#include"display-circle.hpp"
#include"vector3d.hpp"
#include"const.hpp"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace std;

DisplayCircle::DisplayCircle(){};

sf::CircleShape DisplayCircle::getShape(){return _shape;};

void DisplayCircle::setTexture(sf::Texture* tex){
    _shape.setTexture(tex);
};

void DisplayCircle::setPosition(const Vector3d v){
    Vector3d tmp=v/DIST_DISPLAY;
    _shape.setPosition(X0_DISPLAY+tmp(0), Y0_DISPLAY+tmp(1));
};

void DisplayCircle::setSize(const Vector3d v){
    Vector3d tmp=v/SCALE_DISPLAY;
    tmp[0]=(tmp[0]<MIN_DISPLAY)? MIN_DISPLAY : tmp[0];
    tmp[1]=(tmp[1]<MIN_DISPLAY)? MIN_DISPLAY : tmp[1];
    tmp[2]=(tmp[2]<MIN_DISPLAY)? MIN_DISPLAY : tmp[2];
    _shape.setRadius(tmp(0));
    _shape.setOrigin(tmp(0), tmp(0));
};

void DisplayCircle::setColor(sf::Color c){
    _shape.setFillColor(c);
};
