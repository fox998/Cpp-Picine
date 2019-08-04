
#include    "GraphicalMode.hpp"
#include    <stdlib.h>
#include    <iostream>
#include    <unistd.h>
#include    <string>

bool GraphicalMode::std_init = 0;

GraphicalMode::GraphicalMode()
{
    SDL_Color       textColor = { 0, 0, 0, 0xFF };

    if (!std_init)
    {
        std_init = 1;
        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();
    }

    w = 500;
    h = 500; 

    wind = SDL_CreateWindow("FT_GKRELLM", 0, 0, w, h, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    font = TTF_OpenFont( "ARIAL.TTF", 100 );
    srf  = TTF_RenderText_Solid( font, "CPU ", textColor );
    texture = SDL_CreateTextureFromSurface( rend, srf);


    SDL_Surface *                   _hostname;
    SDL_Surface *                   _username;
    SDL_Surface *                   _vershon;
    SDL_Surface *                   _data;
    SDL_Surface *                   _ramSrf;
    SDL_Surface *                   _cpuNameSrf;
    SDL_Surface *                   _networkInSrf;
    SDL_Surface *                   _networkOutSrf;


    _genInfo.setData();
    _dataTime.setData();
    _cpu.setData();
    _network.setData();
    std::string         Host = "Hostname : " + _genInfo.getHostname();
    std::string         User = "Username : " + _genInfo.getUser();
    std::string         Versh = "Vershen : " + _genInfo.getVersion();
    std::string         Datas = "Data : " + _dataTime.getDate();
    std::string         NetworIn = "Networ In : " + _network.getIn();
    std::string         NetworOut = "Networ Out : " + _network.getOut();
   // std::string         CpuName = "CPU : " + _cpu.getCPUGeneral();

    _hostname = TTF_RenderText_Solid( font, &Host[0], textColor );
    _username = TTF_RenderText_Solid( font, &User[0], textColor );
    _vershon = TTF_RenderText_Solid( font, &Versh[0], textColor );
    _data = TTF_RenderText_Solid( font, &Datas[0], textColor );
    _ramSrf = TTF_RenderText_Solid( font, "RAM : ", textColor );
    _cpuNameSrf = TTF_RenderText_Solid( font, "CPU : Intel(R) Core(TM) i5-7500 CPU @ 3.40GHz", textColor );
    _networkInSrf = TTF_RenderText_Solid( font, &NetworIn[0], textColor );
    _networkOutSrf = TTF_RenderText_Solid( font, &NetworOut[0], textColor );

    _hostnameTextr  = SDL_CreateTextureFromSurface( rend,  _hostname);
    _usernameTextr = SDL_CreateTextureFromSurface( rend,  _username);
    _vershonTextr = SDL_CreateTextureFromSurface( rend, _vershon);
    _dataTextr = SDL_CreateTextureFromSurface( rend, _data);
    _ramTextr = SDL_CreateTextureFromSurface( rend, _ramSrf);
    _cpuNameTextr = SDL_CreateTextureFromSurface( rend, _cpuNameSrf);
    _networInTextr = SDL_CreateTextureFromSurface( rend, _networkInSrf);
    _networOutTextr = SDL_CreateTextureFromSurface( rend, _networkOutSrf);

    SDL_FreeSurface(_hostname);
    SDL_FreeSurface(_username);
    SDL_FreeSurface(_vershon);
    SDL_FreeSurface(_data);
    SDL_FreeSurface(_ramSrf);
    SDL_FreeSurface(_cpuNameSrf);
    SDL_FreeSurface(_networkInSrf);
    SDL_FreeSurface(_networkOutSrf);    

}


GraphicalMode::~GraphicalMode(){}

void                GraphicalMode::loop()
{
    bool            f = false;
	SDL_Event       e;
    CPU             c;

    SDL_Color       textColor = { 0, 0, 0, 0xFF };
    SDL_Surface *                   _timeSrf;
    std::string                     Time;
    std::string                     FreeRAM;
    std::string                     UsedRAM;

    SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
    int             cpuBarH = 50;

    SDL_Rect        hostRect = {10, cpuBarH * 0, w / 2 - 10, cpuBarH};
    SDL_Rect        nameRect = {10, cpuBarH * 1, w / 2 - 10, cpuBarH};
    SDL_Rect        vershRect = {10, cpuBarH * 2, w / 2 - 10, cpuBarH};
    SDL_Rect        dataRect = {10, cpuBarH * 3, w / 2 - 10, cpuBarH};
    SDL_Rect        timeRect = {10, cpuBarH * 4, w / 2 - 10, cpuBarH};
    SDL_Rect        cpuNameRect = {10, cpuBarH * 5, w / 2 - 10, cpuBarH};
    SDL_Rect        networInRect = {10, cpuBarH * 6, w / 2 - 10, cpuBarH};
    SDL_Rect        networOutRect = {10, cpuBarH * 7, w / 2 - 10, cpuBarH};

    SDL_Rect renderQuad = { 10, h - cpuBarH - 5, w / 2 - 10, cpuBarH };
    SDL_Rect cpuFullBar = { 220, h - cpuBarH - 5, w / 2 - 10, cpuBarH };
    SDL_Rect cpuPrecentBar = { 220, h - cpuBarH - 5, 0, cpuBarH };

    SDL_Rect ramQuad = { 10, h - cpuBarH * 2 - 6, w / 2 - 10, cpuBarH };
    SDL_Rect freeRamBar = { 220, h - cpuBarH * 2 - 6, w / 2 - 10, cpuBarH };
    SDL_Rect usedRamBar = { 220, h - cpuBarH * 2 - 6, 0, cpuBarH };

    while( !f )
	{

        _dataTime.setData();
        Time = "Time : " + _dataTime.getTime();
        _timeSrf = TTF_RenderText_Solid( font, &Time[0], textColor );
        _timeTextr = SDL_CreateTextureFromSurface( rend, _timeSrf);
        SDL_FreeSurface(_timeSrf);

        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderCopyEx( rend, texture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _hostnameTextr, NULL, &hostRect, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _usernameTextr, NULL, &nameRect, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _vershonTextr, NULL, &vershRect, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _dataTextr, NULL, &dataRect, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _timeTextr, NULL, &timeRect, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _ramTextr, NULL, &ramQuad, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _cpuNameTextr, NULL, &cpuNameRect, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _networInTextr, NULL, &networInRect, 0, NULL, SDL_FLIP_NONE );
        SDL_RenderCopyEx( rend, _networOutTextr, NULL, &networOutRect, 0, NULL, SDL_FLIP_NONE );


        SDL_DestroyTexture(_timeTextr);





        SDL_RenderFillRect(rend, &cpuFullBar);
        SDL_SetRenderDrawColor( rend, 0xFF, 0x0F, 0x0F, 0xFF );
        c.setData();
        cpuPrecentBar.w = static_cast<int>(c.getCPUTRunning()) * cpuFullBar.w / 100;
        //std::cout << cpuPrecentBar.w << std::endl;
        SDL_RenderFillRect(rend, &cpuPrecentBar);

        _ram.setData();
        int             allRam = _ram.getRAMFree() + _ram.getRAMUsed();
        freeRamBar.w = _ram.getRAMFree() * (100.0 / allRam);
        usedRamBar.x = freeRamBar.w + freeRamBar.x;
        usedRamBar.w = _ram.getRAMUsed() * (100.0 / allRam);
        SDL_SetRenderDrawColor( rend, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderFillRect(rend, &usedRamBar);
        SDL_SetRenderDrawColor( rend, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect(rend, &freeRamBar);



        SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderPresent( rend );
        //usleep(500000);
        while( SDL_PollEvent( &e ) != 0 )
		{
            e.type == SDL_QUIT || (e.type == SDL_KEYDOWN &&
			e.key.keysym.sym == SDLK_ESCAPE) ? (f = 1) : 0;
		}
	}

}


void                    GraphicalMode::displayGeneralInformation()
{
    //SDL_Color       textColor = { 0, 0, 0, 0xFF };


    /*SDL_Surface *                   _hostname;
    SDL_Surface *                   _username;
    SDL_Surface *                   _vershon;
    SDL_Surface *                   _datatime;

    _genInfo.setData();
    std::string         Host;
    std::string         User;
    Host = "Hostname : " + _genInfo.getHostname();
    User = "Username : " + _genInfo.getUser();
    _hostname = TTF_RenderText_Solid( font, &Host[0], textColor );

    _hostnameTextr  = SDL_CreateTextureFromSurface( rend,  _hostname);
    _usernameTextr = SDL_CreateTextureFromSurface( rend,  _username);
    _vershonTextr = SDL_CreateTextureFromSurface( rend, _vershon);
    _datatimeTextr = SDL_CreateTextureFromSurface( rend, _datatime);*/
}
void                    GraphicalMode::displayDateTime()
{

}

void                    GraphicalMode::displayCPU(){}
void                    GraphicalMode::displayRAM(){}
void                    GraphicalMode::displayNetwork(){}
