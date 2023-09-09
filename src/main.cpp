#include "common.hpp"
#include "game_objects/food.hpp"
#include "game_objects/snake.hpp"

int frame_count = 0;
int score       = 0;

int main() {
	auto window = std::make_unique<raylib::Window>(g_screen_width, g_screen_height, "Snake Game");

	SetTargetFPS(g_game_fps);

	auto food_instance  = std::make_unique<food>();
	auto snake_instance = std::make_unique<snake>();

	while (!window->ShouldClose()) {
		// Input
		snake_instance->input();

		// Update
		if (g_running) {
			if (frame_count % g_game_speed == 0) {
				snake_instance->update();

				if (snake_instance->check_collision()) {
					g_running = false;
					snake_instance->reset();
					food_instance->update(snake_instance->body());
					score = 0;
				}

				if (snake_instance->body().front() == food_instance->position()) {
					score++;
					snake_instance->add();
					food_instance->update(snake_instance->body());
				}
			}
		} else {
			raylib::DrawText("GAME OVER", ((float)g_screen_width / 2) - (3 * 40), ((float)g_screen_height / 2) - 20, 40, g_dark_green);
		}

		// Draw
		BeginDrawing();
		{
			window->ClearBackground(g_green);

			food_instance->draw();
			snake_instance->draw();

			window->DrawFPS(10, 10);
			DrawText(std::to_string(score), g_screen_width - 60, 10, 30, g_dark_green);
		}
		EndDrawing();

		frame_count++;
	}

	window->Close();
	return 0;
}
