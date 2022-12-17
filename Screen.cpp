#include "Screen.h"

namespace dmc
{

  Screen::Screen()
      : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr),
        m_pixel_mem(nullptr) {}

  bool Screen::init()
  {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      return false;
    }

    m_window = SDL_CreateWindow(
        "Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        screen_width, screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (m_window == NULL)
    {
      SDL_Quit();
      return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (m_renderer == NULL)
    {
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }

    m_texture =
        SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                          SDL_TEXTUREACCESS_STATIC, screen_width, screen_height);

    if (m_texture == NULL)
    {
      SDL_DestroyRenderer(m_renderer);
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }

    m_pixel_mem = new Uint32[screen_width * screen_height];
    memset(m_pixel_mem, 0, screen_width * screen_height * sizeof(Uint32));

    return true;
  }

  bool Screen::process_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return false;
      }
    }
    return true;
  }

  void Screen::set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    
    if(x < 0 || x >= screen_width || y < 0 || y >= screen_height){
      return; // Prevent the pxel from being drawn off the screen
    }

    // Remember at the end that the last 8 bits will be statically setting the ALPHA
    Uint32 color {0};

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF; // statically setting the ALPHA bits
    color <<= 0;   // Shifting them 0 as they are already on the end

    m_pixel_mem[(y * screen_width) + x] = color;
  }

  void Screen::update(){
    SDL_UpdateTexture(m_texture, NULL, m_pixel_mem,
                      screen_width * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

  }

  void Screen::close()
  {
    delete[] m_pixel_mem;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
  }

} // namespace dmc
