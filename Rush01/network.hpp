#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
private:
	std::string		_network_in;
	std::string		_network_out;

public:
	Network();
	~Network();
	Network(Network const &src);
	Network & operator=(Network const &src);

	std::string     getIn() const;
	std::string     getOut() const;

	void            setData();
	
};

#endif
