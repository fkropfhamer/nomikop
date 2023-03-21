cmake_minimum_required(VERSION 3.5)
project(nomikop)

set(CMAKE_CXX_STANDARD 23)
set(CMaKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2b")

add_subdirectory(deps/sdl EXCLUDE_FROM_ALL)

add_executable(nomikop main.cpp)

target_link_libraries(nomikop PRIVATE SDL3::SDL3)

