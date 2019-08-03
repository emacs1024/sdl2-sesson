#
# learn web address
# http://lazyfoo.net/tutorials/SDL/index.php
#

cmake_minimum_required(VERSION 3.13)
project(demo)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        .
        lesson
)

add_executable(
        demo

        # source code
        IBaseDisplay.h
        IBaseDisplay.cc

        lesson/L1.h lesson/L1.cc
        lesson/L2.h lesson/L2.cc

        init.h init.cc

        main.cpp
        lesson/L4.cpp lesson/L4.h)

target_link_libraries(
        demo

        # library
        SDL2
)