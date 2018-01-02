cmake_minimum_required(VERSION 3.9)
project(Client)
set(Boost_INCLUDE_DIR C:/cygwin64/packages/boost_1_66_0)
set(Boost_LIBRARY_DIR C:/cygwin64/packages/boost_1_66_0)
find_package(Boost)
include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(Client main.cpp)