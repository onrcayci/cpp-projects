# minimum required cmake version=3.10
cmake_minimum_required(VERSION 3.10)

project(DicePoker)

set(EXEC dice_poker)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC src/*.cpp)

add_executable(${EXEC} ${SRC})