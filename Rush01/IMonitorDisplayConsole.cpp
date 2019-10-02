#include "IMonitorDisplayConsole.hpp"

WINDOW *                    IMonitorDisplayConsole::getWindow1() const {return _main;};
WINDOW *                    IMonitorDisplayConsole::getWindow2() const {return _main2;};
IMonitorGeneralInformation  IMonitorDisplayConsole::getGenera() const{return _generalInformation;};
DateTime                    IMonitorDisplayConsole::getDateTime() const{return _dateTime;};
CPU                         IMonitorDisplayConsole::getCPU() const{return _CPU;};
RAM                         IMonitorDisplayConsole::getRam() const{return _RAM;};;
Network                     IMonitorDisplayConsole::getNetwork() const{return _network;};


IMonitorDisplayConsole::IMonitorDisplayConsole(IMonitorDisplayConsole const &src) 
{
    *this = src;
}
IMonitorDisplayConsole &IMonitorDisplayConsole::operator=(IMonitorDisplayConsole const & src)
{
    _main = src.getWindow1();
    _main2 = src.getWindow2();
    _generalInformation = src.getGenera();
    _dateTime = src.getDateTime();
    _CPU = src.getCPU();
    _RAM = src.getRam();   
    _network = src.getNetwork();
    return *this;
}

IMonitorDisplayConsole::IMonitorDisplayConsole()
{
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);

    _main = newwin(30, 80, 2, 150);
    box (_main, 0,0);
    _main2 = newwin(20, 80, 32, 150);
    box (_main2, 0,0);
    refresh();
    
    this->_generalInformation.setData();
}

IMonitorDisplayConsole::~IMonitorDisplayConsole()
{
	endwin();
}

void                    IMonitorDisplayConsole::displayGeneralInformation() // +
{
    wattron(_main, COLOR_PAIR(1));
    wattron(_main, A_BOLD);
    mvwprintw(_main,3,28, "General information:");
    wattroff(_main, COLOR_PAIR(1));

    wmove(_main,4,2);
    whline(_main, '-', 76);  
	mvwprintw(_main,5,2, "Hostname                   ->    %s;", _generalInformation.getHostname().c_str());
   	mvwprintw(_main,6,2, "User                       ->    %s;", _generalInformation.getUser().c_str());
    mvwprintw(_main,7,2, "Version                    ->    %s;", _generalInformation.getVersion().c_str());
}

void                    IMonitorDisplayConsole::displayDateTime() // +
{
        mvwprintw(_main,1,2, "Date: %s", _dateTime.getDate().c_str());
        mvwprintw(_main,1,64, "Time: %s", _dateTime.getTime().c_str());
}

void                    IMonitorDisplayConsole::displayCPU() // -
{
        wattron(_main, COLOR_PAIR(1));
        wattron(_main, A_BOLD);
        mvwprintw(_main,9,35, "CPU:");
        wattroff(_main, COLOR_PAIR(1));

        wmove(_main,10,2);
        whline(_main, '-', size_arr);  

        mvwprintw(_main,11,2, "CPU:                      ->    %s;", "Intel(R) Core(TM) i5-7500 CPU @ 3.40GHz");
        mvwprintw(_main,12,2, "CPU cores:                ->    %s;", "4");
        mvwprintw(_main,13,2, "CPU processes:            ->    %d;", _CPU.getCPUTotal());
        mvwprintw(_main,14,2, "CPU threads:              ->    %d;", _CPU.getCPUThreads());
        mvwprintw(_main,15,2, "CPU usage:                ->    %.f%%;", _CPU.getCPUTRunning());
}

void                    IMonitorDisplayConsole::displayRAM() // +
{

        wattron(_main, COLOR_PAIR(1));
        wattron(_main, A_BOLD);
        mvwprintw(_main,18,35, "RAM:");
        wattroff(_main, COLOR_PAIR(1));

        wmove(_main,19,2);
        whline(_main, '-', size_arr);  

        mvwprintw(_main,20,2, "RAM Used:                 ->    %d;", _RAM.getRAMUsed());
        mvwprintw(_main,21,2, "RAM Free:                 ->    %d;", _RAM.getRAMFree());
}

void                    IMonitorDisplayConsole::displayNetwork()
{
    wattron(_main, COLOR_PAIR(1));
    wattron(_main, A_BOLD);
    mvwprintw(_main,24,35, "Network:");
    wattroff(_main, COLOR_PAIR(1));

    wmove(_main,25,2);
    whline(_main, '-', size_arr);  
    mvwprintw(_main,26,2, "Network IN, M:            ->    %s;", _network.getIn().c_str());
    mvwprintw(_main,27,2, "Network OUT, M:           ->    %s;", _network.getOut().c_str());
}

void IMonitorDisplayConsole::showArray(WINDOW *main, int *arr)
{
    int i = 2;
    int j = 0;
    
    while (j < size_arr)
    {
        wattron(main, COLOR_PAIR(3));
        wattron(main, A_BOLD);
        drawLine(main, coord_y, i++, arr[j++]);
        wattroff(main, COLOR_PAIR(3));
    }
    wrefresh(main);

}

void    IMonitorDisplayConsole::init_zero(int *arr, int value)
{
    int i = 0;

    arr[i] = value;
}

void    IMonitorDisplayConsole::zero_it(int *arr)
{
    int i = 0;

    while (i < size_arr)
         arr[i++]=rand()% 5 + 1;


}

void    IMonitorDisplayConsole::replace(int *arr)
{
    int i = size_arr - 1;
    while (i != 0)
    {
        arr[i] = arr[i-1];
        i--;
    }
}

void            IMonitorDisplayConsole::drawLine(WINDOW * main, int y, int x, int distance) const
{
    while (distance != 0)
    {
        mvwprintw(main, y++, x, ".");
        distance--;
    }
}

void IMonitorDisplayConsole::displayGraph(int *arr)
{
    wclear(_main2);
    box (_main2, 0,0);
    wattron(_main2, COLOR_PAIR(2));
    wattron(_main2, A_BOLD);
    mvwprintw(_main2,2,35, "CPU:");
    wattroff(_main2, COLOR_PAIR(2));

    wmove(_main2,3,2);
    whline(_main2, '-', size_arr);
    wrefresh(_main2);
    replace(arr);
    init_zero(arr, _CPU.getCPUTRunning());
    
    showArray(_main2, arr);
}

void                    IMonitorDisplayConsole::loop()
{
    int arr[size_arr];
    zero_it(arr);

    while (1)
    {
        clear();

        this->_dateTime.setData();
        this->_CPU.setData();
        this->_RAM.setData();
        this->_network.setData();

        this->displayDateTime();
		this->displayGeneralInformation();
        this->displayCPU();
        this->displayRAM();
        this->displayNetwork();

        wrefresh(_main);

        displayGraph(arr);
	}
}
