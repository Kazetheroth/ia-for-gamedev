cmake_minimum_required(VERSION 3.17)
project(GOAP)

set(CMAKE_CXX_STANDARD 14)

include_directories(GOAP/GOAP)
include_directories(GOAP/GOAP/Debug)
include_directories(GOAP/GOAP/x64)
include_directories(GOAP/GOAP/x64/Debug)

add_executable(GOAP
        GOAP/GOAP/Debug/GOAP.pch
        GOAP/GOAP/x64/Debug/GOAP.pch
        GOAP/GOAP/Actions.cpp
        GOAP/GOAP/Actions.h
        GOAP/GOAP/Condition.h
        GOAP/GOAP/Effect.cpp
        GOAP/GOAP/Effect.h
        GOAP/GOAP/GoapSolver.cpp
        GOAP/GOAP/GoapSolver.h
        GOAP/GOAP/main.cpp
        GOAP/GOAP/pch.cpp
        GOAP/GOAP/pch.h
        GOAP/GOAP/Precondition.cpp
        GOAP/GOAP/Precondition.h
        GOAP/GOAP/World.cpp
        GOAP/GOAP/World.h)
