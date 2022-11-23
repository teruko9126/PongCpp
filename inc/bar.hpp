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

  enum class Direction
  {
    UP,
    DOWN,
    NONE
  };
  // コンストラクタ
  Bar(Type type, int x, int y);
  // デコンストラクタ
  ~Bar() = default;

  void handle_input(SDL_Event const &event);
  void draw(SDL_Renderer *renderer);
  void update(double delta_time);

private:
  SDL_Rect bar_position;
  Type bar_type;
  Direction bar_direction = Direction::NONE;

  double bar_speed = 1000;
  double position_y;
};