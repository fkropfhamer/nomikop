cmake_minimum_required(VERSION 3.5)
project(nomikop)

set(CMAKE_CXX_STANDARD 23)
set(CMaKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2b")

if(WIN32)
    set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif ()

add_subdirectory(deps/SDL EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
