cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# SDL2 paths
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/lib/SDL2")
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include/SDL2")

# Include directories
include_directories(
    header 
    include
    ${SDL2_INCLUDE_DIR}
)

# Collect all .cpp files from src/
file(GLOB SOURCES "src/*.cpp")

# Create executable from source files
add_executable(MyExecutable ${SOURCES})

target_include_directories(MyExecutable PRIVATE 
    header 
    include
    ${SDL2_INCLUDE_DIR}
)

# Link SDL2
target_link_libraries(MyExecutable PRIVATE 
    ${SDL2_DIR}/libSDL2.a
    ${SDL2_DIR}/libSDL2main.a
    -lmingw32  # Required for MinGW
    winmm
    kernel32
    user32
    gdi32
    winspool
    shell32
    ole32
    oleaut32
    uuid
    comdlg32
    advapi32
    setupapi
    imm32
    version
    cfgmgr32
)