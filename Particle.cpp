#include "Particle.h"
#include <stdlib.h>

namespace dmc{

Particle::Particle(){
    m_xcord = ((2.0 * rand())/RAND_MAX) - 1;
    m_ycord = ((2.0 * rand())/RAND_MAX) - 1;
}

}