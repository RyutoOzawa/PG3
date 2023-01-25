#include<stdio.h>
#include"Circle.h"
#include"RectAngle.h"

int main() {
	Circle circle1;
	circle1.r = 4.0f;
	circle1.size();
	circle1.draw();
	RectAngle rect1;
	rect1.w = 3.0f;
	rect1.h = 5.0f;
	rect1.size();
	rect1.draw();

	return 0;
}