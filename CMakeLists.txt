cmake_minimum_required(VERSION 2.8.11)

project(tictactoe)

SET(CMAKE_CXX_FLAGS "-std=c++11")

set(PROJECT_HEADER_FILES ${PROJECT_SOURCE_DIR}/hdr)

include_directories("${PROJECT_HEADER_FILES}")

add_subdirectory(ttt_lib)
add_subdirectory(ttt_frontend)
add_subdirectory(ttt_backend)
