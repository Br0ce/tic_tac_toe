cmake_minimum_required(VERSION 2.8.11)

project(ttt_backend)


# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Network)
find_package(OpenCV REQUIRED )

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


set(HEADER_FILES
        hdr/action.h
        hdr/alpha_beta.h
        hdr/dispatcher.h
        hdr/engine.h
        hdr/min_max.h
        hdr/move_algorithm.h
        hdr/pitch.h
        hdr/server.h
        )

set(SOURCE_FILES
        src/action.cpp
        src/alpha_beta.cpp
        src/dispatcher.cpp
        src/engine.cpp
        src/main.cpp
        src/min_max.cpp
        src/move_algorithm.cpp
        src/pitch.cpp
        src/server.cpp
        )


include_directories(${Qt5Widgets_LIBRARIES})
include_directories(${Qt5Network_LIBRARIES})
include_directories(${PROJECT_HEADER_FILES})

add_executable(ttt_backend ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(ttt_backend Qt5::Widgets)
target_link_libraries(ttt_backend Qt5::Network)
target_link_libraries(ttt_backend ttt_lib)
target_link_libraries(ttt_backend ${OpenCV_LIBS} )

