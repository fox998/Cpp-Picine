
#ifndef     GRAPHICALMODE_HPP
# define    GRAPHICALMODE_HPP

#include    "SDL_image.h"
#include    "SDL_mixer.h"
#include    "SDL_ttf.h"
#include    "SDL_net.h"
#include    "IMonitorDisplay.hpp"
#include    "IMonitorGeneralInformation.hpp"
#include    "CPU.hpp"
#include    "DateTime.hpp"
#include    "RAM.hpp"
#include    "network.hpp"

class       GraphicalMode : public IMonitorDisplay
{
    private:
        int             w;
        int             h;

        SDL_Window *    wind;
        SDL_Renderer *  rend;
        SDL_Surface *   srf;
        TTF_Font *      font;
        SDL_Texture *   texture;


        IMonitorGeneralInformation      _genInfo;
        CPU                             _cpu;
        DateTime                        _dataTime;
        RAM                             _ram;
        Network                         _network;



        SDL_Texture *                   _hostnameTextr;
        SDL_Texture *                   _usernameTextr;
        SDL_Texture *                   _vershonTextr;
        SDL_Texture *                   _dataTextr;
        SDL_Texture *                   _timeTextr;
        SDL_Texture *                   _ramTextr;
        SDL_Texture *                   _cpuNameTextr;
        SDL_Texture *                   _networInTextr;
        SDL_Texture *                   _networOutTextr;

        static bool     std_init;

    public:
        GraphicalMode();
        ~GraphicalMode();
        GraphicalMode(GraphicalMode const & copy);

        GraphicalMode &             operator=(GraphicalMode const & copy);

        //void                    displayCPU();

        virtual void                    displayGeneralInformation();
	    virtual void                    displayDateTime();
	    virtual void                    displayCPU();
	    virtual void                    displayRAM();
	    virtual void                    displayNetwork();

        void                loop();
};

#endif