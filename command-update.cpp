#include<iostream>
#include<unistd.h>
#include"graph.hpp"
#include"command.hpp"
#include"command-update.hpp"
using namespace std;

CommandUpdate::CommandUpdate(Graph& _graph_in):
    Command(_graph_in){};

void CommandUpdate::execute(){
    while(!_end){
        usleep(TIME_FLUSH);
        _graph.setStatusAll();
        _graph.setForceAll();
    }
};
