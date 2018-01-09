//
// Created by yoav on 09/01/18.
//

#ifndef ASSIGNMENT3_TASK_H
#define ASSIGNMENT3_TASK_H

#include "../include/connectionHandler.h"

class Task {
private:
    ConnectionHandler *connectionHandler;
public:
    Task(ConnectionHandler *connectionHandler);

    void sendMsg();
};

#endif