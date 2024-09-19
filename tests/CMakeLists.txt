cmake_minimum_required(VERSION 3.16)
project(googletests)

set(CMAKE_INSTALL_MESSAGE LAZY)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -lgmock -pthread")

add_compile_options(-fprofile-arcs -ftest-coverage)
link_libraries(gcov)

set(SOURCE_EXE runtests.cpp test_from.cpp test_to.cpp test_dialogs.cpp)

include_directories(../task) # Расположение заголовочных файлов (for compiler to find)
include_directories(../dialog) # Расположение заголовочных файлов (for compiler to find)

# создание исполняемого файла
add_executable(test ${SOURCE_EXE})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../task ${CMAKE_CURRENT_BINARY_DIR}/task)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../dialog ${CMAKE_CURRENT_BINARY_DIR}/dialog)

target_link_libraries(test task)
target_link_libraries(test dialog)
target_link_libraries(test gtest)