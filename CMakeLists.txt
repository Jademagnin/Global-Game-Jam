cmake_minimum_required(VERSION 3.13)  # CMake version check
project(jam)               # Create project "jam"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard

# Use GLOB_RECURSE to include all .cpp files recursively
file(GLOB_RECURSE SOURCE_FILES "./src/*.cpp")

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(jam ${SOURCE_FILES})

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(jam sfml-graphics sfml-audio)