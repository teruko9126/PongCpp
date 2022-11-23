#pragma once
#include <SDL2/SDL.h>
#include "bar.hpp"

class Pong
{
public:
  Pong();
  ~Pong();

  void loop();

  void update(double delta_time);
  void draw();

private:
  Bar left_bar;
  Bar right_bar;

  SDL_Window *game_window;
  SDL_Renderer *game_window_renderer;
  SDL_Event m_window_event;
};