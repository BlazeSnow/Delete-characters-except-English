cmake_minimum_required(VERSION 3.28)
project(Delete_characters_except_English)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

include_directories(.)

add_executable(Delete_characters_except_English
        main.cpp)
