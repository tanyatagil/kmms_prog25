#!/bin/bash

MAIN=after_refactoring_2.cpp
APP=after_refactoring_2

if [ -f $APP ]; then
    rm $APP
fi

g++ -std=c++17 -Wall $MAIN -o $APP

./$APP
