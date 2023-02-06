cmake_minimum_required(VERSION 3.24)
project(Notes_Bartoloni)

set(CMAKE_CXX_STANDARD 17)

add_executable(Notes_Bartoloni main.cpp Note.cpp Note.h Collection.cpp Collection.h Observer.h Subject.h)
