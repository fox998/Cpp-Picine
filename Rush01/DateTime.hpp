#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "IMonitorModule.hpp"

class DateTime : public IMonitorModule
{
private:
	std::string		_date;
	std::string		_time;
public:
	DateTime();
	~DateTime();
	DateTime(DateTime const &src);
	DateTime & operator=(DateTime const &src);

	std::string const&		getDate() const;
	std::string const&		getTime() const;

	void            setData();
	
};

#endif
