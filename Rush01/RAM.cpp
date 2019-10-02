#include "RAM.hpp"

RAM::RAM() {};
RAM::~RAM() {};

int             RAM::getRAMUsed() const {return _RAM_used;};
int             RAM::getRAMFree() const {return _RAM_free;};

RAM::RAM(RAM const &src) 
{
    *this = src;
}
RAM &RAM::operator=(RAM const & src)
{
   _RAM_used = src.getRAMUsed();
   _RAM_free = src.getRAMFree();
    return *this;
}

void RAM::setData()
{
    std::string data[2];
    
    char buff[BUFSIZE];

    std::string result = "";

    FILE * fp = popen("sh ram.sh","r");  

    while (fgets( buff, BUFSIZE, fp )!=NULL)
        result+= buff;
    pclose(fp);

    std::istringstream f(result);

    std::string line;    

    int i = 0;

    while (std::getline(f, line)) 
    {
        line.erase(std::remove(line.begin(), line.end(), '%'), line.end());

        line.erase(std::remove(line.begin(), line.end(), 'M'), line.end());

        data[i] = line;

        i++;
    }
    _RAM_used = atoi(data[0].c_str());
    _RAM_free = atoi(data[1].c_str());
}

