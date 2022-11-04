#include <SDL2/SDL.h>
#include <iostream>
#include "bar.hpp"

Bar::Bar(Type type, int x, int y)
{
  bar_position.x = x;
  bar_position.y = y;
  bar_position.w = 20;
  bar_position.h = 60;

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