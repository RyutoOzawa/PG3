#pragma once
#include"IShape.h"

class Circle :public IShape
{
public:
	float x = 0;
	float y = 0;
	float r = 0;



	void size() override;
	void draw() override;

private:
	float mySize = 0;

};

