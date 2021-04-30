# minimum required cmake version=3.10
cmake_minimum_required(VERSION 3.10)

project(DicePoker)

set(EXEC dice_poker)

set(CMAKE_CXX_STANDARD 17)

file(GLOB LIB src/*/*.cpp)

add_executable(${EXEC} ${LIB} "src/main.cpp")