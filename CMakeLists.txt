cmake_minimum_required(VERSION 3.16)
project(oop_lab_1)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCE_EXE run.cpp)

include_directories(dialog task) # Расположение заголовочных файлов (for compiler to find)

# создание исполняемого файла
add_executable(run ${SOURCE_EXE})

add_subdirectory(dialog)
add_subdirectory(task)

target_link_libraries(run dialog)
target_link_libraries(run task)