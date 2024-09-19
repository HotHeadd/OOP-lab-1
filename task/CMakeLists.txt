cmake_minimum_required(VERSION 3.16)
project(task_functions)

set(SOURCE_LIB from_yaml.cpp to_yaml.cpp)
# создание библиотеки
add_library(task STATIC ${SOURCE_LIB})