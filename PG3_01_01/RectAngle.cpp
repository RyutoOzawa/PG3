#include "RectAngle.h"
#include<stdio.h>

void RectAngle::size()
{
	mySize = w * h;
}

void RectAngle::draw()
{
	printf("�ʐ�:%f\n", mySize);
}
