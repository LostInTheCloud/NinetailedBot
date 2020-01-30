# cmake_minimum_required(VERSION <specify CMake version here>)
project(NinetailedBot C)

set(CMAKE_C_STANDARD 99)

link_directories(${CMAKE_SOURCE_DIR})

add_executable(NineTailedBot main.c)

target_link_libraries(NineTailedBot twirc pthread)