#pragma once

#include "common.hpp"

class food {
public:
    food();
    void draw();
    void update(std::deque<raylib::Vector2> snake_body);
    raylib::Vector2 position();

private:
    raylib::Vector2 rand_pos();

private:
    raylib::Vector2 m_position;
};
