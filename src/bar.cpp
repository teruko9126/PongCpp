#include <SDL2/SDL.h>
#include <iostream>
#include "bar.hpp"

Bar::Bar(Type type, int x, int y)
{
  bar_position.x = x;
  bar_position.y = y;
  bar_position.w = 20;
  bar_position.h = 60;
  bar_direction = Direction::NONE;
  position_y = static_cast<double>(y);

  bar_type = type;
}

void Bar::draw(SDL_Renderer *renderer)
{
  // renderで使う色を白に変化
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_RenderFillRect(renderer, &bar_position);
  // renderで使う色を基準色の黒に戻す
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Bar::update(double delta_time)
{
  if (bar_direction == Direction::UP)
    position_y -= bar_speed * delta_time;
  else if (bar_direction == Direction::DOWN)
    position_y += bar_speed * delta_time;

  bar_position.y = position_y;
  bar_direction = Direction::NONE;
}

void Bar::handle_input(SDL_Event const &event)
{
  switch (event.type)
  {
  case SDL_KEYDOWN:
    Uint8 const *keys = SDL_GetKeyboardState(nullptr);

    // handle input of left bar
    if (bar_type == Type::LEFT)
    {
      if (keys[SDL_SCANCODE_W])
        bar_direction = Direction::UP;
      else if (keys[SDL_SCANCODE_S])
        bar_direction = Direction::DOWN;
    }
    // handle input of right bar
    else if (bar_type == Type::RIGHT)
    {
      if (keys[SDL_SCANCODE_UP])
        bar_direction = Direction::UP;
      else if (keys[SDL_SCANCODE_DOWN])
        bar_direction = Direction::DOWN;
    }
  }
}