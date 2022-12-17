#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace dmc
{

  class Screen
  {
  public:
    constexpr static int screen_width = 800;
    constexpr static int screen_height = 600;

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_pixel_mem;

  public:
    Screen();
    bool init();
    void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    bool process_events();
    void close();
  };

} // namespace dmc
#endif
