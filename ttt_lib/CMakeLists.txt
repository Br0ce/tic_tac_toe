cmake_minimum_required(VERSION 2.8.11)

project(ttt_lib)


set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

set(${PROJECT_HEADER_FILES} ${HEADER_FILE})



set(HEADER_FILE
        hdr/helper.h
        )

set(SOURCE_FILE
        src/helper.cpp
        )


include_directories(${HEADER_FILE})

add_library(ttt_lib ${SOURCE_FILE})

target_link_libraries(ttt_lib)
