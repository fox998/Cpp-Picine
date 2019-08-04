#include "IMonitorDisplayConsole.hpp"
#include "IMonitorModule.hpp"
#include "GraphicalMode.hpp"
#include <string>


int main(int argc, char **argv)
{
	std::string param(argv[argc - 1]);
	if (param == "C")
	{
		IMonitorDisplayConsole *c = new IMonitorDisplayConsole();
		c->loop();
		delete c;
	}
	else
	{
		GraphicalMode	g;
		g.loop();
	}
	return (0);
}