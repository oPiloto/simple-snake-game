#include "snake.hpp"

snake::snake() : m_body({{4, 5}, {3, 5}, {2, 5}}), m_direction(RIGHT) {}

void snake::input() {
	if (IsKeyPressed(KEY_W) && m_direction != DOWN && m_can_move) {
		m_direction = UP;
		m_can_move  = false;
		g_running   = true;
	}
	if (IsKeyPressed(KEY_S) && m_direction != UP && m_can_move) {
		m_direction = DOWN;
		m_can_move  = false;
		g_running   = true;
	}
	if (IsKeyPressed(KEY_A) && m_direction != RIGHT && m_can_move) {
		m_direction = LEFT;
		m_can_move  = false;
		g_running   = true;
	}
	if (IsKeyPressed(KEY_D) && m_direction != LEFT && m_can_move) {
		m_direction = RIGHT;
		m_can_move  = false;
		g_running   = true;
	}
}

void snake::update() {
	m_body.pop_back();
	switch (m_direction) {
	case UP: m_body.push_front(Vector2Add(m_body.front(), {0, -1})); break;
	case DOWN: m_body.push_front(Vector2Add(m_body.front(), {0, 1})); break;
	case LEFT: m_body.push_front(Vector2Add(m_body.front(), {-1, 0})); break;
	case RIGHT: m_body.push_front(Vector2Add(m_body.front(), {1, 0})); break;
	}
	m_can_move = true;
}

void snake::draw() {
	for (auto i : m_body)
		DrawRectangle(i.x * g_cell_size, i.y * g_cell_size, g_cell_size, g_cell_size, g_dark_green);
}

void snake::add() { m_body.push_back(m_body.back()); }

std::deque<raylib::Vector2> snake::body() { return m_body; }

bool snake::check_collision() {
	// Check collision with edges
	if (m_body.front().x == g_cell_count || m_body.front().x == -1)
		return true;

	if (m_body.front().y == g_cell_count || m_body.front().y == -1)
		return true;

	// Check collision with itself
	bool head = true;
	for (auto vac : m_body) {
		if (!head) {
			if (m_body.front() == vac)
				return true;
		} else {
			head = false;
		}
	}

	return false;
}

void snake::reset() {
	m_body      = {{4, 5}, {3, 5}, {2, 5}};
	m_direction = RIGHT;
}
