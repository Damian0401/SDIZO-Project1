# CMakeList.txt : CMake project for SDIZO, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SDIZO   "main.cpp" "include/Array.hpp" "src/Array.cpp"  "include/ListNode.hpp" "include/List.hpp" "src/List.cpp" "include/Heap.hpp" "src/Heap.cpp" "include/interface/Timer.hpp" "src/interface/Timer.cpp"  "include/SDIZO.hpp"  "include/interface/Menu.hpp" "src/interface/Menu.cpp" "include/interface/Tests.hpp" "src/interface/Tests.cpp" "include/interface/Enums.hpp" "include/TreeNode.hpp" "include/Tree.hpp" "src/Tree.cpp" "src/interface/ManualTests.cpp" "src/interface/AutomaticTests.cpp" "include/interface/ManualTests.hpp" "include/interface/AutomaticTests.hpp")

# TODO: Add tests and install targets if needed.
