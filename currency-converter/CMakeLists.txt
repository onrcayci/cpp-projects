# define compatible cmake version >= 3.10
cmake_minimum_required(VERSION 3.10)

# project name
project(currency-converter)

# executable name
set(EXEC convertcur)

# set the C++ 20 standard
set(CMAKE_CXX_STANDARD 20)

# put all .cpp files under src to the project
file(GLOB SRC src/*.cpp)

# compile the files defined by SRC to generate the executable defined by EXEC
add_executable(${EXEC} ${SRC})

# add private libraries
target_link_libraries(${EXEC} PRIVATE curl curlpp jsoncpp)

# update install paths
install(TARGETS ${EXEC} DESTINATION bin)