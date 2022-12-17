#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SDL2/SDL.h>

namespace dmc{

class Particle{
    
    public: // For efficiency instead of calling Getters() over and over in the game loop.
        double m_xcord{0};
        double m_ycord{0};

    public:
        Particle();
};

}
#endif