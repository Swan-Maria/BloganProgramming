#include <stdio.h>

struct Point
{
	double x;
	double y;
};

int main(void)
{
	struct Point origin;

	origin.x = 10;
	origin.y = 20;

	printf("Hello World");

	return 0;
}