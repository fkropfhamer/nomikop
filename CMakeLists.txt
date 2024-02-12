cmake_minimum_required(VERSION 3.5)
project(
    nomikop
    LANGUAGES C
    )

if(WIN32)
    set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

add_subdirectory(deps/SDL EXCLUDE_FROM_ALL)
add_subdirectory(deps/SDL_ttf EXCLUDE_FROM_ALL)

include(sources.cmake)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}
        src/text.c
        src/text.h)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf)

install(DIRECTORY assets DESTINATION ${CMAKE_BINARY_DIR})
