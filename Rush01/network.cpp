#include "network.hpp"

Network::Network() {};
Network::~Network() {};

Network::Network(Network const &src) 
{
    *this = src;
}
Network &Network::operator=(Network const & src)
{
   _network_in = src.getIn();
   _network_out = src.getOut();
    return *this;
}

std::string const&    Network::getIn() const {return _network_in;};
std::string const&    Network::getOut() const {return _network_out;};

void	Network::setData()
{

	std::string result = "";
    {
	    char buff[BUFSIZE];
	    FILE * fp = popen("sh network.sh","r");	

	    while (fgets( buff, BUFSIZE, fp )!=NULL)
  	    	result+= buff;
	    pclose(fp);
    }

	std::istringstream f(result);

    std::string line;    

    int i = 0;

    std::string data[2];
    while (std::getline(f, line)) 
    {
    	line.erase(std::remove(line.begin(), line.end(), '%'), line.end());

    	line.erase(std::remove(line.begin(), line.end(), 'M'), line.end());

        data[i] = line;

        i++;
    }
    _network_in = data[0];
    _network_out = data[1];
}
