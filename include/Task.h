#ifndef TASK__
#define TASK__

#include "ConnectionHandler.h"

class Task {
private:

    ConnectionHandler *connectionHandler;

public:

    Task(ConnectionHandler *connectionHandler);

    void sendMsg();
};

#endif