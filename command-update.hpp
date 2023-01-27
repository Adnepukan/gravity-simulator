#ifndef COMMAND_UPDATE_HPP
#define COMMAND_UPDATE_HPP
#include"graph.hpp"
#include"command.hpp"

class CommandUpdate: public Command{
    public:
        CommandUpdate(Graph& _graph_in);
        void execute();
};

#endif
