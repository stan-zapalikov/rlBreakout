#include "Ball.h"
#include "raylib.h"

void Ball::Draw() {
	DrawCircle(x, y, radius, WHITE);
}

void Ball::Update(Player player, Brick* (*bricks)[6]) {
	x += speedX;
	y += speedY;

	if (x <= radius || x >= GetScreenWidth() - radius) {
		speedX *= -1;
	}
	if (y <= radius) {
		speedY *= -1;
	}
	if (CheckCollisionCircleRec(Vector2{ x, y },
		radius,
		Rectangle{ player.getX(), player.getY(), player.getSizeX(), player.getSizeY() })) {
		speedY *= -1;
	}

	if (y >= GetScreenHeight() - radius) {
		Reset();
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (CheckCollisionCircleRec(Vector2{ x, y },
				radius,
				Rectangle{ bricks[i][j]->getX(), bricks[i][j]->getY(),
					bricks[i][j]->getSizeX(), bricks[i][j]->getSizeY() })
				&& bricks[i][j]->Displayed())
			{
				speedY *= -1;
			}
		}
	}
}

void Ball::Reset() {
	const int directions[2] = { -1, 1 };
	speedX *= directions[GetRandomValue(0, 1)];
	speedY *= directions[GetRandomValue(0, 1)];
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;
}

Ball::Ball(float newX, float newY, float newSpeedX, float newSpeedY, int newRadius) {
	x = newX;
	y = newY;
	speedX = newSpeedX;
	speedY = newSpeedY;
	radius = newRadius;
}

void Ball::setX(float newX) {
	x = newX;
}

void Ball::setY(float newY) {
	y = newY;
}

void Ball::setSpeedX(float newSpeedX) {
	speedX = newSpeedX;
}

void Ball::setSpeedY(float newSpeedY) {
	speedY = newSpeedY;
}

void Ball::setRadius(int newRadius) {
	radius = newRadius;
}

float Ball::getX() {
	return x;
}

float Ball::getY() {
	return y;
}

float Ball::getSpeedX() {
	return speedX;
}

float Ball::getSpeedY() {
	return speedY;
}

int Ball::getRadius() {
	return radius;
}

