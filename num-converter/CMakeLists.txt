# cmake minimum version requirement = 3.10
cmake_minimum_required(VERSION 3.10)

# initialize project
project(number-converter)

# set executable
set(EXEC convertnum)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

# set source files
file(GLOB SRC src/*.cpp)

# complie the files defined by SRC
add_executable(${EXEC} ${SRC})