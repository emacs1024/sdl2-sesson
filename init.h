
#ifndef _INIT_H_INCLUDE
#define _INIT_H_INCLUDE

#include "IBaseDisplay.h"
#include "L1.h"

using init_func = IBaseDisplay * ();

struct Init
{
    int         index;
    const char *desc;
    init_func  *func;
};

extern Init instance[];

IBaseDisplay *create_display_by_index(int index );

void display_usage();


#endif //_INIT_H_INCLUDE
