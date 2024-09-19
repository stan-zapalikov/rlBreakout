#include "Player.h"
#include "raylib.h"

Player::Player(float newX, float newY, float newSizeX, float newSizeY, int newSpeed) {
	x = newX;
	y = newY;
	sizeX = newSizeX;
	sizeY = newSizeY;
	speed = newSpeed;
}

void Player::Draw() {
	DrawRectangle(x, y, sizeX, sizeY, WHITE);
}

void Player::Update() {
	if (IsKeyDown(KEY_LEFT) && x > 0) {
		x -= speed;
	}
	if (IsKeyDown(KEY_RIGHT) && x < GetScreenWidth() - sizeX) {
		x += speed;
	}
	
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		x = GetMouseX();
}

float Player::getX() {
	return x;
}

float Player::getY() {
	return y;
}

float Player::getSizeX() {
	return sizeX;
}

float Player::getSizeY() {
	return sizeY;
}
