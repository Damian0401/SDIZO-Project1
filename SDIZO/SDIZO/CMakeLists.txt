# CMakeList.txt : CMake project for SDIZO, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SDIZO   "main.cpp" "include/Array.hpp" "src/Array.cpp"  "include/ListNode.hpp" "include/List.hpp" "src/List.cpp")

# TODO: Add tests and install targets if needed.
