#pragma once
#include "ECS.h"

class PositionComponent : public Component {
private:
	int xPos = 0;
	int yPos = 0;

public:
	int x() { return xPos; }
	int y() { return yPos; }

	void init() override {
		xPos = 0;
		yPos = 0;
	}

	void update() override {
		xPos++;
		yPos++;
	}

	void setPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};