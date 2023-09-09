#pragma once

#include "common.hpp"

enum direction { UP, DOWN, LEFT, RIGHT };

class snake {
public:
    snake();
    void input();
    void update();
    void draw();
    void add();
    std::deque<raylib::Vector2> body();
    bool check_collision();
    void reset();

private:
    std::deque<raylib::Vector2> m_body;
    direction m_direction;
    bool m_can_move;
};
