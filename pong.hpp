#pragma once
#include <SDL2/SDL.h>
// #include "Bar.h"

class Pong
{
public:
  Pong();
  ~Pong();

  void loop();

private:
  // Bar player_bar;
  // Bar enemy_bar;
  
  SDL_Window *game_window;
  SDL_Event m_window_event;
};