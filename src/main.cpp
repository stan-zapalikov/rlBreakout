#include "raylib.h"
#include "Ball.h"
#include "Player.h"
#include "Brick.h"
#include <iostream>

int main() {
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	Ball ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 4, 4, 15);
	Player player(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 30, 150, 20, 5);

	Brick* bricks[4][6];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			float temp = (SCREEN_WIDTH / 6);
			std::cout << temp << std::endl;
			bricks[i][j] = new Brick(50 + (200 * j), 50 + (70* i), 150, 20);
		}
	}

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout");

	SetTargetFPS(144);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 6; j++) {
				bricks[i][j]->Draw();
				bricks[i][j]->Update(ball.getX(), ball.getY(), ball.getRadius());
			}
		}

		ball.Draw();
		ball.Update(player, bricks);
		player.Draw();
		player.Update();
		EndDrawing();
	}

	CloseWindow();
}