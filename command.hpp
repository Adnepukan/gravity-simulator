#ifndef COMMAND_HPP
#define COMMAND_HPP
#include"graph.hpp"

class Command{
    protected:
        Graph& _graph;
        bool _end;
    public:
        Command(Graph&);
        bool getEnd();
        void setEnd();
        virtual ~Command();
        virtual void execute()=0;
};

#endif
