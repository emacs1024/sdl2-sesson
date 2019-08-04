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
        lesson/L4.h lesson/L4.cc
        lesson/L5.h lesson/L5.cc
        lesson/L7.h lesson/L7.cc
        lesson/L8.h lesson/L8.cc

        init.h init.cc

        main.cpp
        )

target_link_libraries(
        demo

        # library
        SDL2 SDL2_image
)