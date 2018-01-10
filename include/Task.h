#ifndef TASK__
#define TASK__

#include "ConnectionHandler.h"

class Task {
private:

    ConnectionHandler *connectionHandler;
    std::atomic<bool> *loggedIn;

public:

    Task(ConnectionHandler *connectionHandler, std::atomic<bool> *loggedIn);
    void sendMsg();
};

#endif