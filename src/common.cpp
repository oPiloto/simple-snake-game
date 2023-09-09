#include "common.hpp"

bool g_running = true;

const int g_cell_size  = 30;
const int g_cell_count = 25;

const int g_game_fps = 60;
const int g_game_speed = 6;

constexpr int g_screen_width  = g_cell_size * g_cell_count;
constexpr int g_screen_height = g_cell_size * g_cell_count;

raylib::Color g_green      = {137, 193, 110, 255};
raylib::Color g_dark_green = {34, 74, 41, 255};
raylib::Color g_red        = {212, 63, 63, 255};