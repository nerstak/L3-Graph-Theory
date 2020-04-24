cmake_minimum_required(VERSION 3.6) # Version for CMake
project(Graph_Theory) # Project name

# List of cpp files
set(SRC
		Int1-9_main.cpp
		Int1-9_Graph.cpp
		Int1-9_MatrixValue.cpp
		Int1-9_readGraphFile.cpp
		Int1-9_interface.cpp
		Int1-9_logs.cpp
		Int1-9_loop.cpp
		Int1-9_rank.cpp
		Int1-9_Schedule.cpp
		Int1-9_scheduling.cpp
		Int1-9_schedulable.cpp
        )


# List of h files
set(HDR
		Int1-9_Graph.h
		Int1-9_MatrixValue.h
		Int1-9_readGraphFile.h
		Int1-9_interface.h
		Int1-9_logs.h
		Int1-9_Schedule.h
        )

set(CMAKE_CXX_STANDARD 17) # Version of C++
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../) # Output in root folder

add_executable(Graph_Theory ${SRC} ${HDR})