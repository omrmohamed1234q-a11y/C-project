cmake_minimum_required(VERSION 4.1)
project(C_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(core)
include_directories(Custumer)
include_directories(Owner)
include_directories(Users)

add_executable(C_project
        core/Login.cpp
        core/Login.hpp
        core/Room.cpp
        core/Room.hpp
        core/RoomTypes.cpp
        core/RoomTypes.hpp
        core/Workspace.cpp
        core/Workspace.hpp
        Custumer/costumer.cpp
        Custumer/costumer.h
        Owner/Owner.cpp
        Owner/Owner.h
        Users/Users.cpp
        Users/users.h
        main.cpp)
