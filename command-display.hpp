#ifndef COMMAND_DISPLAY_HPP
#define COMMAND_DISPLAY_HPP
#include"command.hpp"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

class CommandDisplay: public Command{
    private:
        sf::RenderWindow& _window;
    public:
        CommandDisplay(Graph&, sf::RenderWindow&);
        void execute();
};

#endif
