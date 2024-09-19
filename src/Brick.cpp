#include "Brick.h"

Brick::Brick() {
	x = 0;
	y = 0;
	sizeX = 0;
	sizeY = 0;
	isDisplaying = true;
}

Brick::Brick(float newX, float newY, float newSizeX, float newSizeY) {
	x = newX;
	y = newY;
	sizeX = newSizeX;
	sizeY = newSizeY;
	isDisplaying = true;
}

void Brick::Draw() {
	if (isDisplaying) {
		DrawRectangle(x, y, sizeX, sizeY, RED);
	}
}

void Brick::Update(float ballX, float ballY, int ballRadius) {
	if (CheckCollisionCircleRec(Vector2{ ballX, ballY },
		ballRadius,
		Rectangle{ x, y, sizeX, sizeY })) 
	{
		isDisplaying = false;
	}
}

float Brick::getX() {
	return x;
}

float Brick::getY() {
	return y;
}

float Brick::getSizeX() {
	return sizeX;
}

float Brick::getSizeY() {
	return sizeY;
}

bool Brick::Displayed() {
	return isDisplaying;
}
