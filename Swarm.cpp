#include "Swarm.h"

namespace dmc{

Swarm::Swarm(){
    m_p_particles = new Particle[n_particles];
}

const Particle* const Swarm::get_particles(){
    return m_p_particles;
}

Swarm::~Swarm(){
    delete[] m_p_particles;
}

}