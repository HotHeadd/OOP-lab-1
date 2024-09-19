cmake_minimum_required(VERSION 3.16)
project(dialog_functions)

set(SOURCE_LIB dialogs.cpp get_values.cpp)
# создание библиотеки
add_library(dialog STATIC ${SOURCE_LIB})