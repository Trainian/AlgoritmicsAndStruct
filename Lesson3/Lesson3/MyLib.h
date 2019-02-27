#pragma once
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

clock_t start, stop;

void Pause()
{
	_getch();
}

void Time_start()
{
	start = clock();
}

long Time_stop()
{
	stop = clock();
	return stop - start;
}

void RusLang()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void Change_numb()
{
	int *x;
	int *y;
	//*x=10;                                    // Так нельзя!
	//*y=30;                                    // Так нельзя!
	int a = 10, b = 30;
	//*x=a;                                      // И так нельзя!
	//*y=b;                                      // И так нельзя!
	x = &a;                                       // Теперь указатель хранит в себе адрес a
	y = &b;
	printf("a=%i b=%i\n", a, b);        // Берём значения
	printf("&x=%p &y=%p\n", x, y); // Выведем адреса
	printf("x=%i y=%i\n", *x, *y);     // Берём значения
	//Передаем адреса x и y
	swap(x, y);                                // Так как x и y хранят адреса, операция & не требуется
	// Выведем адреса
	printf("&x=%p &y=%p\n", x, y);
	// Выводим значения
	printf("a=%i b=%i\n", a, b);        // Берём значения
	printf("x=%i y=%i\n", *x, *y);      // Значения поменялись
	printf("Время прошедшее: %d millisecond\n", Time_stop());
}

int SumDigit(long a)
{
	int s = 0;
	while (a > 0)
	{
		s = s + a % 10;
		a = a / 10;
	}
	return s;
}

long Reverse(long n)
{
	long newN = 0;
	while (n > 0)
	{
		newN = newN * 10 + n % 10;
		n /= 10;
	}
	return newN;
}

long Pow(int a, int b)//a^b
{
	long n = 1, s = a, k = b;
	while (k != 0) {
		if (k % 2 == 0)
		{
			s = s * s; k /= 2;
		}
		else
		{
			k--;
			n = n * s;
		}
	}
	return n;
}

double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
