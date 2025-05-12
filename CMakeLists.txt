cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(header)

# Collect all .cpp files from src/
file(GLOB SOURCES "src/*.cpp")

# Create executable from source files
add_executable(MyExecutable ${SOURCES})