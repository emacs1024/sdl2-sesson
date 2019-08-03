
#include <set>
#include <iostream>
#include <iomanip>

#include "init.h"
#include "L1.h"
#include "L2.h"
#include "L4.h"

Init instance[] =
{
    {
        .index = 2,
        .desc  = "tutorial - getting an image on the screen",
        .func  = L1::initialize
    },

    {
        .index = 3,
        .desc  = "Event Driven Programming",
        .func  = L2::initialize
    },

    {
        .index = 4,
        .desc  = "Key Presses",
        .func  = L4::initialize
    }

};

IBaseDisplay *create_display_by_index(int index )
{
    for (auto& init : instance)
    {
        if (init.index == index)
        {
            return init.func();
        }
    }
    return nullptr;
}

void display_usage()
{
    std::cout << "---------------------------------------------------------------------------" << std::endl;
    std::cout << "|   index   |                       description" << std::endl;
    std::cout << "---------------------------------------------------------------------------" << std::endl;
    for (auto& init : instance)
    {
        std::cout << "|  " << std::setw(4) << init.index << "     | " << init.desc << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------" << std::endl;
}
