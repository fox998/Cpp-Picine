#ifndef RAM_HPP
#define RAM_HPP

#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
private:

	int 			_RAM_used;
	int 			_RAM_free;

public:
	RAM();
	~RAM();
	RAM(RAM const &src);
	RAM & operator=(RAM const &src);

	int             getRAMUsed() const;
	int             getRAMFree() const;

	void            setData();
	
};

#endif
