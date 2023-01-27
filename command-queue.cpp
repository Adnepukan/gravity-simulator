#include<iostream>
#include<pthread.h>
#include<queue>
#include"command-queue.hpp"
#include"command.hpp"
using namespace std;

queue<Command*> CommandQueue::q;
CommandQueue* CommandQueue::CommandQueue_ptr=NULL;
CommandQueue::CommandQueue(){};
CommandQueue::~CommandQueue(){};
CommandQueue* CommandQueue::newCommandQueue(){
    if(CommandQueue_ptr==NULL)
        CommandQueue_ptr=new CommandQueue;
    return CommandQueue_ptr;
};

void* CommandQueue::threadInvoke(void*){
    Command* c=q.front();
    q.pop();
    c->execute();
    delete c;
    return NULL;
};

int CommandQueue::autoInvoke(){
    int tnum=q.size();
    pthread_t tids[tnum];
    void* treturns[tnum];
    int tcreate=0;
    for(int i=0; i<tnum; i+=(tcreate==0))
        tcreate=pthread_create(&tids[i], NULL, threadInvoke, NULL);
    for(int i=0; i<tnum; ++i)
        pthread_join(tids[i], &treturns[i]);
    return 0;
};

void CommandQueue::push(Command* c){q.push(c);};
