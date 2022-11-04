#pragma once

#include <SDL2/SDL.h>

class Bar
{
public:
  // barの種類を区別するためのenum
  enum class Type
  {
    LEFT,
    RIGHT
  };
  // コンストラクタ
  Bar(Type type, int x, int y);
  // デコンストラクタ
  ~Bar() = default;
  void draw(SDL_Renderer *renderer);

private:
  SDL_Rect bar_position;
  Type bar_type;
};