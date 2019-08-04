#include "DateTime.hpp"

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

std::string     DateTime::getDate() const {return _date;};
std::string     DateTime::getTime() const {return _time;};

void DateTime::setData()
{
 std::string data[2];
    
    char buff[BUFSIZE];

    std::string result = "";

    FILE * fp = popen("sh DateTime.sh","r");  

    while (fgets( buff, BUFSIZE, fp )!=NULL)
        result+= buff;
    pclose(fp);

    std::istringstream f(result);

    std::string line;    

    int i = 0;

    while (std::getline(f, line)) 
    {
        data[i] = line;
        i++;
    }
    _date = data[0];
    _time = data[1];
}