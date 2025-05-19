cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(header include)

# Collect all .cpp files from src/
file(GLOB SOURCES "src/*.cpp")

# Create executable from source files
add_executable(MyExecutable ${SOURCES})

target_include_directories(MyExecutable PRIVATE header include)
link_directories(${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(MyExecutable PRIVATE ${CMAKE_SOURCE_DIR}/lib/libglfw3.a opengl32)