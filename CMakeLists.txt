# CMakeList.txt : CMake project for UppgiftA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#project ("test")
project (graph)
# Add source to this project's executable.
#add_executable (test "Graph.h" "GraphMain.cpp")
add_executable (graph "Graph.h" "tester.cpp")

# TODO: Add tests and install targets if needed.

