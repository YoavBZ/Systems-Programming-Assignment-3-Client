project(Client)
set(Boost_INCLUDE_DIR /home/tal/Downloads/boost_1_66_0)
set(Boost_LIBRARY_DIR /home/tal/Downloads/boost_1_66_0)
find_package(Boost)
include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(Client src/main.cpp src/connectionHandler.cpp src/echoClient.cpp)