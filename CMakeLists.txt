cmake_minimum_required(VERSION 3.6) # Version for CMake
project(Graph_Theory) # Project name

# List of cpp files
set(SRC
        main.cpp
        src/Graph.cpp
        src/MatrixValue.cpp
        src/readGraphFile.cpp
        src/interface.cpp
        src/logs.cpp
        src/loop.cpp
        src/rank.cpp
        )


# List of h files
set(HDR
        src/Graph.h
        src/MatrixValue.h
        src/readGraphFile.h
        src/interface.h
        src/logs.h
        src/rank.cpp
        )

set(CMAKE_CXX_STANDARD 17) # Version of C++
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../) # Output in root folder

add_executable(Graph_Theory ${SRC} ${HDR})