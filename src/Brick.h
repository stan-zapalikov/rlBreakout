#pragma once

#include "raylib.h"
class Brick {
private:
	float x, y;
	float sizeX, sizeY;
	bool isDisplaying;
public:
	Brick();
	Brick(float newX, float newY, float newSizeX, float newSizeY);
	void Draw();
	void Update(float ballX, float ballY, int ballRadius);

	float getX();
	float getY();
	float getSizeX();
	float getSizeY();

	bool Displayed();
};
