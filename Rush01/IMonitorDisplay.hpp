#ifndef     IMONITORDISPLAY_HPP
# define    IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"

class       IMonitorDisplay
{
public:
	virtual void                    displayGeneralInformation() = 0;
	virtual void                    displayDateTime() = 0;
	virtual void                    displayCPU() = 0;
	virtual void                    displayRAM() = 0;
	virtual void                    displayNetwork() = 0;
    virtual void                    loop() = 0;
};

#endif