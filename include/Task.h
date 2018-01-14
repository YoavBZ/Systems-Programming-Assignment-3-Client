#ifndef TASK__
#define TASK__

#include "ConnectionHandler.h"

class Task {
private:

    ConnectionHandler *connectionHandler;
    std::atomic<bool> *shouldTerminate;

public:

    Task(ConnectionHandler *connectionHandler, std::atomic<bool> *shouldTerminate);
    void sendMsg();
};

#endif