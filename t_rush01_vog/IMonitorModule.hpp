#ifndef     IMONITORMODULE_HPP
# define    IMONITORMODULE_HPP

#include <iostream>
#include <sstream>

#define BUFSIZE 2048

class       IMonitorModule
{
    public:
        virtual void                    setData() = 0;
};

#endif