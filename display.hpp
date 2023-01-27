#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include<iostream>
#include"vector3d.hpp"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

class Display{
    public:
        Display();
        void setTexture(sf::Texture* tex);
        void setPosition(const Vector3d=Vector3d(0,0,0));
        void setSize(const Vector3d=Vector3d(0,0,0));
        void setColor(sf::Color=sf::Color::Blue);
};
#endif
