#include<iostream>
#include"command.hpp"
using namespace std;

Command::Command(Graph& _graph_in):
    _graph(_graph_in), _end(false){};
Command::~Command(){};
bool Command::getEnd(){return _end;};
void Command::setEnd(){_end=true;};
