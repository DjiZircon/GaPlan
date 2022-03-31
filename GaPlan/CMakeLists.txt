
cmake_minimum_required(VERSION 3.5)
project(GA_TSP_TEST)
set(include_dirs ${PROJECT_SOURCE_DIR}/test/ ${PROJECT_SOURCE_DIR}/include/)
MESSAGE(${include_dirs})
include_directories(${include_dirs})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
aux_source_directory(. SRC_LIST)
add_compile_options(-std=c++11 -g -Wall)
add_executable(ga_tsp_test ${SRC_LIST})

