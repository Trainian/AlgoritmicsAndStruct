#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Swap.h"
#include "MyLib.h"
typedef struct MyPoint MyPoint;

struct MyPoint
{
	int x;
	int y;
};

int main(int argc, char *argv[])
{
	RusLang();
	Time_start();

	Change_numb();
	printf("Сумма цифр целого числа 124 = %i\n", SumDigit(124));
	printf("Переворот числа 362 = %i\n", Reverse(362));
	printf("Возведение числа 4 в 3-ю степень = %i\n", Pow(4,3));
	MyPoint p1, p2, p3;
	p1.x = 2; p1.y = 3;
	p2.x = 4; p2.y = 6;
	p3.x = 3; p3.y = 5;
	double l1 = Distance(p1.x, p1.y, p2.x, p2.y);
	double l2 = Distance(p1.x, p1.y, p3.x, p3.y);
	double l3 = Distance(p2.x, p2.y, p3.x, p3.y);
	printf("Периметр треугольника (2,3; 4,6; 3,5) = %.2lf\n", l1+l2+l3);

	Pause();
	return 0;
}


