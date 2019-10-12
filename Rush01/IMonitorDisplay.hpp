#pragma once

#include "IMonitorModule.hpp"
#include <string>
#include <array>

namespace MonitorDisplayUtils
{
	std::string getFileData(char const* const file, char const* const flags );
}

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
