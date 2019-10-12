#include "CPU.hpp"
#include "IMonitorDisplay.hpp"
#include <array>

CPU::CPU() {};
CPU::~CPU() {};

CPU::CPU(CPU const &src) 
{
    *this = src;
}
CPU &CPU::operator=(CPU const & src)
{
    _CPU_cores_quantity = src.getCPUCoresQuantity();
    _CPU_general = src.getCPUGeneral();
    _CPU_total = src.getCPUTotal();
    _CPU_threads = src.getCPUThreads();
    _CPU_running =src.getCPUTRunning();
    _CPU_sleeping = src.getCPUSleeping();
    _CPU_usage_user =src.getCPUUsageUser();
    _CPU_usage_system =src.getCPUUsageSystem();
    _CPU_usage_idle =src.getCPUUsageIdle();
    return *this;
}

std::string const&     CPU::getCPUCoresQuantity() const {return _CPU_cores_quantity;};
std::string const&     CPU::getCPUGeneral()  const {return _CPU_general;};
int             CPU::getCPUTotal()  const {return _CPU_total;};
int             CPU::getCPUThreads()  const {return _CPU_threads;};
double          CPU::getCPUTRunning() const {return _CPU_running;};
int             CPU::getCPUSleeping()  const {return _CPU_sleeping;};
int             CPU::getCPUUsageUser()  const {return _CPU_usage_user;};
int             CPU::getCPUUsageSystem()  const {return _CPU_usage_system;};
int             CPU::getCPUUsageIdle()  const {return _CPU_usage_idle;};


void CPU::setData()
{
	std::istringstream f(MonitorDisplayUtils::getFileData("sh CPU.sh", "r"));



    std::array<std::string, 7> data;
    for(decltype(data)::iterator it = data.begin();
        it != data.end() && std::getline(f, *it);
        ++it)
    {
        std::getline(f, *it);
    	//it->erase(std::remove(it->begin(), it->end(), '%'), it->end());
    	//it->erase(std::remove(it->begin(), it->end(), 'M'), it->end());
    }

    _CPU_total = atoi(data[0].c_str());
    _CPU_running = atoi(data[1].c_str());
    _CPU_sleeping = atoi(data[2].c_str());
    _CPU_threads = atoi(data[3].c_str());
    _CPU_usage_user = atoi(data[4].c_str());
    _CPU_usage_system = atoi(data[5].c_str());
    _CPU_usage_idle = atoi(data[6].c_str());
}

