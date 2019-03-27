/*
	1.	Попробовать оптимизировать пузырьковую сортировку. 
		Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
	2.	Реализовать шейкерную сортировку.
	3.	Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
		Функция возвращает индекс найденного элемента или -1, если элемент не найден.
	4.	*Подсчитать количество операций для каждой из сортировок и сравнить его с  асимптотической сложностью алгоритма.

	Реализовать меню с выбором способа заполнения массива: из файла, случайными числами, с клавиатуры
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MaxN 100

void Random (int min, int max, int *mass, int nMass)
{
	for (int i = 0; i < nMass; i++)
	{
		mass[i] = (rand() % (max - min + 1)) + min;
		printf("%d ", mass[i]);
	}
}

void Swap (int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int BubbleSort (int *mass, int nMass)
{
	int i, j, counts = 0;
	   for(i=0;i<nMass;i++)
		for(j=0;j<nMass-1;j++)
		{
			if (mass[j]>mass[j+1])
			{
				Swap(&mass[j],&mass[j+1]);
				counts++;
			}
			counts++;
		}
	return counts;
}

int BubbleSortOptimized (int *mass, int nMass)
{
	int i, j, counts = 0;
	   for(i = 0;i < nMass;i++)
	   {
			for(j = 0;j < nMass - (i+1); j++)
			{
				if (mass[j] > mass[j + 1])
				{
					Swap(&mass[j], &mass[j + 1]);
					counts++;
				}
				counts++;
			}
			counts++;
	   }
	return counts;
}

int ChoiseSort (int *mass, int nMass)
{
	int i, j, jmin, swap = 0, counts = 0;
	for(i = 0; i < nMass; i++)
	{
		jmin = i;
       for(j=i+1;j<nMass;j++)
	   {
		    if (mass[j]<mass[jmin])
           {
               jmin=j;
				swap = 1;
				counts++;
           }
		   	counts++;
	   }
	   if(swap == 1)
	   {
		   	Swap(&mass[i], &mass[jmin]);
			swap = 0;
	   }
	}
	return counts;
}

void Print (int *mass, int nMass)
{
	for(int i = 0; i < nMass; i++)
		printf("%d ", mass[i]);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int mass[MaxN];
	int nMass;
	srand(time(0));
	printf("Введите кол-во элементов в массиве, от 1 до 100\n");
	scanf("%d", &nMass);
	if(nMass < 1 || nMass > 100)
		return 1;
	Random(0,100,mass,nMass);
	//printf("\nCounts on sort = %d\n",BubbleSort(mass,nMass));
	printf("\nCounts on sort = %d\n",BubbleSortOptimized(mass,nMass));
	//printf("\nCounts on sort = %d\n",ChoiseSort(mass,nMass));
	Print(mass, nMass);
	system("pause");
	return 0;
}