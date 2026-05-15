cmake_minimum_required(VERSION 3.16)
project(C_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(core)
include_directories(Custumer)
include_directories(Owner)
include_directories(Users)
include_directories(gui)

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
        gui/MainWindow.cpp
        gui/MainWindow.hpp
        gui/LoginWidget.cpp
        gui/LoginWidget.hpp
        gui/CustomerWidget.cpp
        gui/CustomerWidget.hpp
        gui/OwnerWidget.cpp
        gui/OwnerWidget.hpp
        main.cpp)

target_link_libraries(C_project PRIVATE Qt6::Widgets)
