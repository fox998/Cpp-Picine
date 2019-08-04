#ifndef IMONITORGENERALINFORMATION_HPP
#define IMONITORGENERALINFORMATION_HPP

#include "IMonitorModule.hpp"

class IMonitorGeneralInformation : public IMonitorModule
{
private:
	std::string		_hostname;
	std::string		_user;
	std::string		_version;


public:
	IMonitorGeneralInformation();
	~IMonitorGeneralInformation();
	IMonitorGeneralInformation(IMonitorGeneralInformation const &src);
	IMonitorGeneralInformation & operator=(IMonitorGeneralInformation const &src);

	std::string		getHostname() const;
	std::string		getUser() const;
	std::string		getVersion() const;

	void            setData();
	
};

#endif
