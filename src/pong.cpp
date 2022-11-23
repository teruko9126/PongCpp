#include <SDL2/SDL.h>
#include <iostream>
#include "pong.hpp"

Pong::Pong() : left_bar(Bar::Type::LEFT, 0, (400 / 2) - 50), right_bar(Bar::Type::RIGHT, 400 - 50, (400 / 2) - 50)
{
  SDL_CreateWindowAndRenderer(680, 480, 0, &game_window, &game_window_renderer);

  SDL_RenderSetLogicalSize(game_window_renderer, 400, 400);
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
      }

      left_bar.handle_input(m_window_event);
      right_bar.handle_input(m_window_event);
    }
    update(1.0 / 60.0);
    draw();
  }
}

void Pong::draw()
{
  SDL_RenderClear(game_window_renderer);

  left_bar.draw(game_window_renderer);
  right_bar.draw(game_window_renderer);

  SDL_RenderPresent(game_window_renderer);
}

void Pong::update(double delta_time)
{
  left_bar.update(delta_time);
  right_bar.update(delta_time);
}