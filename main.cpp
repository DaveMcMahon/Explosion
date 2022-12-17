#include "Screen.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include "Particle.h"
#include <stdlib.h>
#include "Swarm.h"

using namespace dmc;

int main() {

  srand(time(nullptr));

  Screen screen;
  Particle particle;
  Swarm swarm;

  if (screen.init() == false) {
    std::cout << "Error initialising SDL" << std::endl;
  }

  while (true) {
    Uint32 time_elapsed = SDL_GetTicks();

    Uint8 green = (unsigned char) ((1+ std::sin(time_elapsed * 0.001)) * 128);
    Uint8 blue = (unsigned char) ((1+ std::sin(time_elapsed * 0.002)) * 128);
    Uint8 red = (unsigned char) ((1+ std::sin(time_elapsed * 0.003)) * 128);
    
    const Particle* const p_particles = swarm.get_particles();
    
    for(int i = 0 ; i < Swarm::n_particles; i++){
      Particle particle = *(p_particles + i);
      
      int x = (particle.m_xcord + 1) * Screen::screen_width / 2;
      int y = (particle.m_ycord + 1) * Screen::screen_height / 2;

      screen.set_pixel(x,y,green,blue,red);
    }

    screen.update();

    if(!screen.process_events()){
      break;
    }
  }

  screen.close();

  return 0;
}
