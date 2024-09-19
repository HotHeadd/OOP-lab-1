#!/bin/sh

mode=$1

if [ $mode -eq 1 ]
then
    mkdir -p buildtest
    cd buildtest
    cmake -Wno-dev ../tests
    make
    cd ..
fi

if [ $mode -eq 2 ] || [ $mode -eq 3 ];
then
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
fi


if [ $mode -eq 1 ]
then
    echo
    ./buildtest/test
fi

if [ $mode -eq 2 ]
then
    echo 
    ./build/run
fi

if [ $mode -eq 3 ]
then
    valgrind --leak-check=full ./build/run
fi

if [ $mode -eq 4 ]
then
    cd buildtest/task/CMakeFiles/task.dir
    lcov --capture --directory . --output-file gtest_coverage.info
    genhtml gtest_coverage.info --output-directory ../../../../COVERAGES/TASK_COVERAGE
    cd ../../../..
fi

if [ $mode -eq 5 ]
then
    cd buildtest/dialog/CMakeFiles/dialog.dir
    lcov --capture --directory . --output-file gtest_coverage.info
    genhtml gtest_coverage.info --output-directory ../../../../COVERAGES/DIALOG_COVERAGE
    cd ../../../..
fi

if [ $mode -eq 6 ]
then
    doxygen
    cd docs/latex
    make
fi