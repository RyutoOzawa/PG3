#include "Circle.h"
#include<stdio.h>

void Circle::size()
{
	mySize = r*r * 3.141592f;
}

void Circle::draw()
{
	printf("ñ êœ:%f\n",mySize);
}
