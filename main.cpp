#include <iostream>

#include "init.h"

int main()
{
    display_usage();

    int index = -1;
    std::cout << "please input the index value you want to create display? ";
    std::cin  >> index;

    IBaseDisplay *display = create_display_by_index(index);
    if (nullptr == display)
    {
        std::cout << "can create display 'IBaseDisplay' object by index " << index << std::endl;
        return 1;
    }

    display->draw();
    delete display;

    return 0;
}
