cmake_minimum_required(VERSION 3.8)
project(UnixFileSystem)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES main.c tree.c tree.h vector.c vector.h system.c system.h parser.c parser.h command_ex.c command_ex.h)
add_executable(UnixFileSystem ${SOURCE_FILES})