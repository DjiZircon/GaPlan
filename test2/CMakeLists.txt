
cmake_minimum_required(VERSION 3.5)
project(GA_TSP_TEST)
aux_source_directory(. SRC_LIST)
add_compile_options(-std=c++11 -g -Wall)
add_executable(ga_tsp_whole_test ${SRC_LIST})