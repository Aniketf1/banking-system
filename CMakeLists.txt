cmake_minimum_required(VERSION 3.4)
project(banking-system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES main.cpp src/*.cpp src/*.h sqlite/*.cpp sqlite/*.h sqlite/sqlite3.c)
add_executable(banking-system ${SOURCE_FILES} src/Bank.cpp src/Bank.h src/Contact.h src/Contact.cpp src/Notification.cpp src/Notification.h)