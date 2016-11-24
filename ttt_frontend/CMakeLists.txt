cmake_minimum_required(VERSION 2.8.11)

project(ttt_frontend)


# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Network)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


set(HEADER_FILES
        hdr/field.h
        hdr/front_win.h
        hdr/session_handler.h
        hdr/socket.h
        )

set(SOURCE_FILES
        src/field.cpp
        src/socket.cpp
        src/session_handler.cpp
        src/front_win.cpp
        src/main.cpp
        )


include_directories(${Qt5Widgets_LIBRARIES})
include_directories(${Qt5Network_LIBRARIES})
include_directories(${PROJECT_HEADER_FILES})

add_executable(ttt_frontend ${SOURCE_FILES} ${HEADER_FILES} )

target_link_libraries(ttt_frontend Qt5::Widgets)
target_link_libraries(ttt_frontend Qt5::Network)
target_link_libraries(ttt_frontend ttt_lib)

