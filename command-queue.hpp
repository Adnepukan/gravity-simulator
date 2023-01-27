#ifndef COMMAND_QUEUE_HPP
#define COMMAND_QUEUE_HPP
#include<queue>
#include<pthread.h>
#include"command.hpp"
#include"command-display.hpp"
#include"command-update.hpp"

class CommandQueue{
    private:
        static queue<Command*> q;
        static CommandQueue* CommandQueue_ptr;
        CommandQueue();
        CommandQueue(CommandQueue&)=delete;
        CommandQueue operator = (CommandQueue&)=delete;
        static void* threadInvoke(void* =NULL);
    public:
        static CommandQueue* newCommandQueue();
        ~CommandQueue();
        static int autoInvoke();
        static void push(Command*);
};

#endif
