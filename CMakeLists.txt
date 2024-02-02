cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled src/main.cpp
        src/PatternScan.hpp
        src/PatternScan.cpp
        src/Protocols.cpp
        src/Protocols.hpp
        src/Memhack.cpp
        src/Memhack.hpp
)
