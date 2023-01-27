#include<iostream>
#include<cmath>
#include"item.hpp"
#include"item-circle.hpp"
#include"force.hpp"
#include"force-gravity.hpp"
#include"vector3d.hpp"
#include"const.hpp"
#include"const-sunearth.hpp"
#include"display.hpp"
#include"display-circle.hpp"
#include"graph.hpp"
#include"command.hpp"
#include"command-update.hpp"
#include"command-display.hpp"
#include"command-queue.hpp"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace std;

int main(){
    ////////// Initial graph
    Graph graph(2);
    graph.setItem(0, new ItemCircle(MASS_SUN, Vector3d(), Vector3d(), RATIO_SUN));
    graph.setItem(1, new ItemCircle(MASS_EARTH, Vector3d(DIST_SUNEARTH,0,0), Vector3d(0,sqrt(G_GRAVITY*MASS_SUN/DIST_SUNEARTH),0), RATIO_EARTH));

    ForceGravity* f=new ForceGravity(graph.getItem(0), graph.getItem(1));
    f->setForce();
    graph.setForce(0,1,f);

    ItemCircle* itemCircle;
    DisplayCircle* displayCircle;

    displayCircle=new DisplayCircle;
    itemCircle=(ItemCircle*)(graph.getItem(0));
    displayCircle->setColor(sf::Color::Red);
    displayCircle->setSize(Vector3d(itemCircle->getEdge(), itemCircle->getEdge(), itemCircle->getEdge()));
    displayCircle->setPosition(itemCircle->getPosition());
    graph.setDisplay(0, displayCircle);

    displayCircle=new DisplayCircle;
    itemCircle=(ItemCircle*)(graph.getItem(1));
    displayCircle->setColor(sf::Color::Blue);
    displayCircle->setSize(Vector3d(itemCircle->getEdge(), itemCircle->getEdge(), itemCircle->getEdge()));
    displayCircle->setPosition(itemCircle->getPosition());
    graph.setDisplay(1, displayCircle);

    ////////// Command Display
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Threebody");
    window.setFramerateLimit(60);

    CommandUpdate commandUpdate(graph);
    CommandDisplay commandDisplay(graph, window);
    CommandQueue* commandQueue=CommandQueue::newCommandQueue();
    CommandQueue::push(&commandUpdate);
    CommandQueue::push(&commandDisplay);
    commandQueue->autoInvoke();

    return 0;
};
