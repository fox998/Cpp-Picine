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

	std::string	const&	getHostname() const;
	std::string	const&	getUser() const;
	std::string	const&	getVersion() const;

	void            setData();
	
};

#endif
