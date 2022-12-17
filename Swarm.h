#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"
#include <SDL2/SDL.h>

namespace dmc {

class Swarm {

public:
  constexpr static int n_particles = 5000;
  const Particle *const get_particles();

private:
  Particle *m_p_particles;

public:
  Swarm();
  ~Swarm();
};

} // namespace dmc
#endif
