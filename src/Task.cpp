//
// Created by yoav on 09/01/18.
//

#include <iostream>
#include <boost/thread.hpp>
#include "../include/Task.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

Task::Task(ConnectionHandler *connectionHandler, std::atomic<bool> *shouldTerminate) : connectionHandler(connectionHandler),
                                                                                       shouldTerminate(shouldTerminate) {}

void Task::sendMsg() {
    while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        if (!connectionHandler->sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        // connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
        if (shouldTerminate) {
            break;
        }
    }
}