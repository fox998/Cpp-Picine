#define size_arr 76
#define coord_y 5

#include "IMonitorDisplay.hpp"
#include "IMonitorGeneralInformation.hpp"
#include "DateTime.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "network.hpp"
#include <ncurses.h>

class IMonitorDisplayConsole : public IMonitorDisplay
{

private:
	WINDOW * 					_main;
	WINDOW * 					_main2;

	IMonitorGeneralInformation 	_generalInformation;
	DateTime 					_dateTime;
	CPU 						_CPU;
	RAM 						_RAM;	
	Network 					_network;


public:
	IMonitorDisplayConsole();
	virtual ~IMonitorDisplayConsole();
	IMonitorDisplayConsole(IMonitorDisplayConsole const &src);
	IMonitorDisplayConsole & operator=(IMonitorDisplayConsole const &src);

	void                   		displayGeneralInformation();
	void                    	displayDateTime();
	void                    	displayCPU();
	void                    	displayRAM();
	void                    	displayNetwork();
	void 						showArray(WINDOW *main, int *arr);
	void   						init_zero(int *arr, int value);
	void  						zero_it(int *arr);
	void    					replace(int *arr);
	void          				drawLine(WINDOW * main, int y, int x, int distance) const;
	void 						displayGraph(int *arr);
	void                    	loop();

	WINDOW *					getWindow1() const;
	WINDOW *					getWindow2() const;

	IMonitorGeneralInformation	getGenera() const;
	DateTime 					getDateTime() const;
	CPU 						getCPU() const;
	RAM 						getRam() const;

	Network 					getNetwork() const;

};