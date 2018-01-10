cmake_minimum_required(VERSION 3.8)
project(Assignment3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

set(SOURCE_FILES src/ClientMain.cpp src/Task.cpp include/Task.h src/ConnectionHandler.cpp include/ConnectionHandler.h)

find_package(Boost COMPONENTS system thread REQUIRED)

if (Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIR})

endif ()

add_executable(Assignment3 ${SOURCE_FILES})

if (Boost_FOUND)
    target_link_libraries(Assignment3 ${Boost_LIBRAIRES})
endif ()