#include "IMonitorDisplayConsole.hpp"
#include "IMonitorModule.hpp"
#include "GraphicalMode.hpp"
#include <string>


int main(int argc, char **argv)
{
	std::string param(argv[argc - 1]);
	if (param == "g")
	{
		GraphicalMode g;
		g.loop();
	}
	else
	{
		IMonitorDisplayConsole c;
		c.loop();
	}
	return (0);
}