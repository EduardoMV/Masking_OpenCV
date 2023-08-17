cmake_minimum_required(VERSION 3.26)
project(ClassWork_170823)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR "E:/opencv-4.8.0/opencv-4.8.0")

find_package(OpenCV REQUIRED PATHS ${OpenCV_DIR})

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ClassWork_170823 main.cpp)

target_link_libraries(ClassWork_150823 ${OpenCV_LIBS})
