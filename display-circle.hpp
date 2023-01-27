#ifndef DISPLAY_CIRCLE_HPP
#define DISPLAY_CIRCLE_HPP
#include<iostream>
#include"vector3d.hpp"
#include"display.hpp"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

class DisplayCircle: public Display{
    private:
        sf::CircleShape _shape;
    public:
        DisplayCircle();
        sf::CircleShape getShape();
        void setTexture(sf::Texture* tex);
        void setPosition(const Vector3d=Vector3d(0,0,0));
        void setSize(const Vector3d=Vector3d(0,0,0));
        void setColor(sf::Color=sf::Color::Blue);
};
#endif
