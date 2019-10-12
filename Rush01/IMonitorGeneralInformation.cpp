#include "IMonitorGeneralInformation.hpp"
#include <string>

IMonitorGeneralInformation::IMonitorGeneralInformation() {};
IMonitorGeneralInformation::~IMonitorGeneralInformation() {};

IMonitorGeneralInformation::IMonitorGeneralInformation(IMonitorGeneralInformation const &src) 
{
    *this = src;
}
IMonitorGeneralInformation &IMonitorGeneralInformation::operator=(IMonitorGeneralInformation const & src)
{
   _hostname = src.getHostname();
   _user = src.getUser();
   _version = src.getVersion();
    return *this;
}


std::string const&    IMonitorGeneralInformation::getHostname() const {return _hostname;};
std::string const&    IMonitorGeneralInformation::getUser() const {return _user;};
std::string const&    IMonitorGeneralInformation::getVersion() const {return _version;};

void IMonitorGeneralInformation::setData()
{
    std::string result = "";
    {
        char buff[BUFSIZE];
        FILE * fp = popen("sh general.sh","r");    

        while (fgets( buff, BUFSIZE, fp )!=NULL)
            result+= buff;
        pclose(fp);
    }

    std::istringstream f(result);

    std::string line;    
    int i = 0;
    std::string data[3];
    while (std::getline(f, line)) {
        data[i] = line;
        i++;
    }

    _hostname = data[0];
    _user = data[1];
    _version = "macOS -> " + data[2];

}