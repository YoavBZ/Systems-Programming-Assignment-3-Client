#include <cstdlib>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "../include/Task.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    std::string host = argv[1];
    short port = atoi(argv[2]);

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    std::atomic<bool> shouldTerminate(false);

    Task task(&connectionHandler, &shouldTerminate);
    boost::thread inputThread(boost::bind(&Task::sendMsg, &task));

    //From here we will see the rest of the client implementation:
    while (1) {

        // We can use one of three options to read data from the server:
        // 1. Read a fixed number of characters
        // 2. Read a line (up to the newline character using the getline() buffered reader
        // 3. Read up to the null character
        std::string answer;
        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }

        int len = answer.length();
		// A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
		// we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);
        std::cout << answer << std::endl;
        if (answer == "ACK signout succeeded") {
            shouldTerminate = true;
            std::cout << "Ready to exit. Press enter\n" << std::endl;
            inputThread.join();
            break;
        }
    }
    return 0;
}