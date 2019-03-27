/*
1.	Создать массив из 100 элементов. Написать программу, которая содержит функции для
	a.	ввода массива с клавиатуры;
	b.	заполняет массив случайными числами;
	c.	подсчета суммы элементов;
	d.	подсчета среднего арифметическое элементов;
	e.	нахождения номера первого элемента, который максимально отличается от среднего арифметического;
	f.	находит максимальное число в массиве;
	g.	*считывает массив из файла. В файле первым числом идет кол-во элементов массива;
	h.	**находит все номера элементов, которые максимально отличаются от среднего арифметического массива;
	i.	сделать каждое задание в виде функции, в которую передается массив.
	j.	**Переписать функции (все или некоторые) с использованием арифметики указателей.
2.	*Выполнить первое задание для двухмерного массива
3.	**Реализовать алгоритм “Решето Эратосфена”.
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MaxN 100

void enterMass(int *mass);
void numberGenerator(int *mass);
int random(int range);
void numberEnter(int *mass);
int summ(int *mass);
float averageMass(int* mass);
int averageDiff(int *mass);
void readFile (int *mass);
void printFile (int *mass, int length);
int FindDublicate2();

int main() 
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int mass[MaxN];

	enterMass(mass);
	printf("Сумма элементов: %i\n", summ(mass));
	printf("Среднее арифметическое: %.2f\n", averageMass(mass));
	printf("Число, которое максимально отличается от среднего арифметического: %i\n", averageDiff(mass));
	printf("Читаем данные с файла 'data.txt': \n");
	readFile(mass);

	system("pause");
}

void enterMass (int *mass)
{
	int a = 0;
	printf("Введите массив в клавиатуры или заполните автоматически:\n");
	printf("1 - Ввод в ручную.\n2 - Автоматическое заполнение\n");
	scanf("%i", &a);
	switch (a)
	{
		case 1:
			numberEnter(mass);
			break;
		case 2:
			numberGenerator(mass);
			break;
		default:
			break;
	}
}

void numberGenerator (int *mass)
{
	for (int i = 0; i < MaxN; i++)
	{
		mass[i] = random(100);
	}
}

int random (int range)
{
	clock_t t = time(NULL);
	ctime(&t);
	return t % range + 1;
}

void numberEnter(int *mass)
{
	for (int i = 0; i < MaxN; i++)
	{
		printf("%s - %i : ", "Enter number from element", i);
		scanf("%i", &mass[i]);
	}
}

int summ(int *mass)
{
	int newSumm = 0;
	for(int i = 0; i < MaxN; i++)
	{
		newSumm += *(mass + i);
	}
	return newSumm;
}

float averageMass(int *mass)
{
	int newSumm = 0;
	int elements = 0;
	for(int i = 0; i < MaxN; i++)
	{
		newSumm += *(mass + i);
		elements++;
	}
	return newSumm / elements;
}

int averageDiff(int *mass)
{
	float avMass = averageMass(mass);
	int numberMax = mass[0];
	float avMaxDiff = 0;
	float t = 0;
	for(int i = 0; i < MaxN; i++)
	{
		t = *(mass + i) - avMass;
		if(t < 0)
			t =-t;
		if(t > avMaxDiff)
			{
				avMaxDiff = t;
				numberMax = *(mass + i);
			}
	}
	return numberMax;
}

void readFile (int *mass)
{
	FILE *file;
	file = fopen("data.txt","r");
	if(file != NULL)
	{
		char string[255];
		fgets(string,255,file);
		int lng = atoi(string);
		for(int i = 0; i < lng; i++)
		{
			fgets(string,255,file);
			int num = atoi(string);
			mass[i] = num;
		}
		printFile(mass,lng);
	}
}

void printFile (int *mass, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%i\t",mass[i]);
	}
}