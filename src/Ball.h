#pragma once
#include "Player.h"
#include "Brick.h"

class Ball {
private:
	float x, y;
	float speedX, speedY;
	int radius;
public:
	Ball(float newX, float newY, float newSpeedX, float newSpeedY, int newRadius);
	void Draw();
	void Update(Player player, Brick* (*bricks)[6]);
	void Reset();

	void setX(float newX);
	void setY(float newY);
	void setSpeedX(float newSpeedX);
	void setSpeedY(float newSpeedY);
	void setRadius(int newRadius);
	
	float getX();
	float getY();
	float getSpeedX();
	float getSpeedY();
	int getRadius();
	
};
