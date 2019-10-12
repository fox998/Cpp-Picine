#include "DateTime.hpp"
#include "IMonitorDisplay.hpp"

DateTime::DateTime() {};
DateTime::~DateTime() {};

DateTime::DateTime(DateTime const &src) 
{
    *this = src;
}

DateTime &DateTime::operator=(DateTime const & src)
{
    _date = src.getDate();
    _time = src.getTime();
    return *this;
}

std::string const&     DateTime::getDate() const {return _date;};
std::string const&     DateTime::getTime() const {return _time;};

void DateTime::setData()
{
    std::istringstream f(MonitorDisplayUtils::getFileData("sh DateTime.sh","r"));

    std::string line;    

    int i = 0;
    std::string data[2];
    while (std::getline(f, line)) 
    {
        data[i] = line;
        i++;
    }

    _date = data[0];
    _time = data[1];
}