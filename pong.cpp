
#include <SDL2/SDL.h>
#include <iostream>
#include "pong.hpp"

Pong::Pong()
{
  game_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
}

Pong::~Pong()
{
  SDL_DestroyWindow(game_window);
}

void Pong::loop()
{
  bool keep_window_open = true;
  while (keep_window_open)
  {
    while (SDL_PollEvent(&m_window_event) > 0)
    {
      switch (m_window_event.type)
      {
      case SDL_QUIT:
        keep_window_open = false;
        break;
      }
    }
  }
}