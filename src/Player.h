#pragma once

class Player {
private:
	float x, y;
	float sizeX, sizeY;
	int speed;
public:
	Player(float newX, float newY, float newSizeX, float newSizeY, int newSpeed);
	void Draw();
	void Update();

	float getX();
	float getY();
	float getSizeX();
	float getSizeY();
	
};


