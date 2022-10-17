#include<stdio.h>

template <typename t>
t Min(t a, t b) {
	if (a > b) {
		return b;
	}
	return a;
}

template <>
char Min<char>(char a, char b) {
	return static_cast<char>('0');
}

int main() {

	int intX = 4;
	int intY = 8;
	float floatX = 1.5f;
	float floatY = 2.3f;
	double doubleX = 1.1412;
	double doubleY = 2.4325;
	char charX = 'c';
	char charY = 'a';

	printf("%d\n", Min<int>(intX, intY));
	printf("%f\n", Min<float>(floatX, floatY));
	printf("%lf\n", Min<double>(doubleX, doubleY));
	if (Min(charX, charY) == '0') {
		printf("”’l‚Ì‘ã“ü‚Í‚Å‚«‚Ü‚¹‚ñ\n");
	}

	return 0;
}