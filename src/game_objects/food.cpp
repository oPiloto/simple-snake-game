#include "food.hpp"
#include "snake.hpp"

food::food() : m_position(rand_pos()) {}

void food::draw() {
	DrawRectangle(m_position.x * g_cell_size, m_position.y * g_cell_size, g_cell_size, g_cell_size, g_red);
}

void food::update(std::deque<raylib::Vector2> snake_body) {
	while (true) {
		bool exit  = true;
		m_position = rand_pos();

		for (auto vec : snake_body)
			if (position() == vec) {
				exit = false;
				break;
			}

		if (!exit)
			continue;

		break;
	}
}

raylib::Vector2 food::rand_pos() {
	return raylib::Vector2(GetRandomValue(0, g_cell_count - 1), GetRandomValue(0, g_cell_count - 1));
}

raylib::Vector2 food::position() { return m_position; }
