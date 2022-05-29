# CMakeList.txt : CMake project for UppgiftA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#project ("test")
project (graph)
project (graph-test1)
# Add source to this project's executable.
#add_executable (test "Graph.h" "GraphMain.cpp")
add_executable (graph  "tester.cpp"  "Graph.cpp")
add_executable (graph-test1  "GraphTest.cpp"  "Graph.cpp")

