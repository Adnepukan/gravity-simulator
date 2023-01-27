#include<iostream>
#include"command.hpp"
#include"command-display.hpp"
#include"item.hpp"
#include"item-circle.hpp"
#include"force.hpp"
#include"force-gravity.hpp"
#include"display.hpp"
#include"display-circle.hpp"
using namespace std;

CommandDisplay::CommandDisplay(Graph& _graph_in,
    sf::RenderWindow& _window_in):
    Command(_graph_in), _window(_window_in){};

void CommandDisplay::execute(){
    _window.setFramerateLimit(60);
    ItemCircle* itemCircle;
    DisplayCircle* displayCircle;
    while (!_end) {
        _window.clear();
        for(int i=0; i<_graph.getSize(); ++i){
            itemCircle=(ItemCircle*)(_graph.getItem(i));
            displayCircle=(DisplayCircle*)(_graph.getDisplay(i));
            displayCircle->setPosition(itemCircle->getPosition());
            _window.draw(displayCircle->getShape());
        }
        _window.display();
    }
};
