cmake_minimum_required(VERSION 3.6) # Version for CMake
project(Graph_Theory) # Project name

# List of cpp files
set(SRC
		Int1-9_main.cpp
		src/Int1-9_Graph.cpp
		src/Int1-9_MatrixValue.cpp
		src/Int1-9_readGraphFile.cpp
		src/Int1-9_interface.cpp
		src/Int1-9_logs.cpp
		src/Int1-9_loop.cpp
		src/Int1-9_rank.cpp
		src/Int1-9_Schedule.cpp
		src/Int1-9_scheduling.cpp
		src/Int1-9_schedulable.cpp
        )


# List of h files
set(HDR
		src/Int1-9_Graph.h
		src/Int1-9_MatrixValue.h
		src/Int1-9_readGraphFile.h
		src/Int1-9_interface.h
		src/Int1-9_logs.h
		src/Int1-9_Schedule.h
        )

set(CMAKE_CXX_STANDARD 17) # Version of C++
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../) # Output in root folder

add_executable(Graph_Theory ${SRC} ${HDR})