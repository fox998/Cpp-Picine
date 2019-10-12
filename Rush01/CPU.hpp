#ifndef CPU_HPP
#define CPU_HPP

#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
private:
	std::string      _CPU_cores_quantity;
	std::string     _CPU_general;
	int             _CPU_total;
	int            _CPU_threads;
	double          _CPU_running;
	int             _CPU_sleeping;
	int             _CPU_usage_user;
	int              _CPU_usage_system;
	int             _CPU_usage_idle;


public:
	CPU();
	~CPU();
	CPU(CPU const &src);
	CPU & operator=(CPU const &src);

	std::string const&     getCPUCoresQuantity()  const;
	std::string const&     getCPUGeneral()  const;
	int             getCPUTotal()  const;
	int             getCPUThreads() const;
	double          getCPUTRunning() const;
	int             getCPUSleeping()  const;
	int             getCPUUsageUser()  const;
	int             getCPUUsageSystem()  const;
	int             getCPUUsageIdle() const;

	void            setData();
	
};

#endif
