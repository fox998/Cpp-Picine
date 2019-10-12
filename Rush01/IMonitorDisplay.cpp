
#include "IMonitorDisplay.hpp"


namespace MonitorDisplayUtils
{
	std::string getFileData(char const* const file, char const* const flags )
    {
        char buff[BUFSIZE];
        FILE * fp = popen(file, flags);	
        std::string result;

        while (fgets( buff, BUFSIZE, fp ) != nullptr)
        {
            result.append(buff);
        }
        pclose(fp);

        return result;
    }
}
