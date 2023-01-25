#pragma once
#include"IShape.h"

class RectAngle : public IShape
{
public:
	float x = 0;
	float y = 0;
	float w = 0;
	float h = 0;

	void size() override;
	void draw() override;

private:
	float mySize = 0;
};

