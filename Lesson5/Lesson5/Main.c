/*
	1.	Попробовать оптимизировать пузырьковую сортировку. 
		Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
	TODO: DONE 0.	Выбор загрузки с файла или генерация случайных чисел.
	TODO: DONE 1.	Реализовать поиск Линейный и половинного деления.
	TODO: 2.	Реализовать шейкерную сортировку.
	TODO: DONE 3.	Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
	TODO: DONE 4.	*Подсчитать количество операций для каждой из сортировок и сравнить его с  асимптотической сложностью алгоритма.
	TODO: DONE 5. Реализовать меню с выбором способа заполнения массива: из файла, случайными числами, с клавиатуры
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define MaxN 100 // Возможно изменить

int mass[MaxN]; // Массив, максимум элементов MaxN
int nMass; // Кол-во элементов в массиве
int exited = 1; // 0 - Выход из программы
FILE *f; // Загрузка с файла

void LoadMass ()
{
	int temp;
	f = fopen("load.txt", "r");
	fscanf(f, "%d", &nMass);
	for(int i = 0; i < nMass; i++)
	{
		fscanf(f, "%d", &temp);
		mass[i] = temp;
	}
	fclose(f);
}

void Randomizer(int min, int max)
{
   printf("%s %d \n","Введите кол-во элементов в массиве, от 1 до", MaxN);
	scanf("%d", &nMass);
	if (nMass < 1 || nMass > MaxN)
	{
		printf("%s", "Введено не корректное значение, повтоите ввод.\n");
      Randomizer(min,max);
	}
	else for (int i = 0; i < nMass; i++)
	{
		mass[i] = (rand() % (max - min + 1)) + min;
	}

}

void Swap(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int BubbleSort()
{
	int i, j, counts = 0;
	for (i = 0; i < nMass; i++)
		for (j = 0; j < nMass - 1; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				Swap(&mass[j], &mass[j + 1]);
				counts++;
			}
			counts++;
		}
	return counts;
}

int BubbleSortOptimized()
{
	int i, j, counts = 0;
	for (i = 0; i < nMass; i++)
	{
		for (j = 0; j < nMass - (i + 1); j++)
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

int ChoiseSort()
{
	int i, j, jmin, swap = 0, counts = 0;
	for (i = 0; i < nMass; i++)
	{
		jmin = i;
		for (j = i + 1; j < nMass; j++)
		{
			if (mass[j] < mass[jmin])
			{
				jmin = j;
				swap = 1;
				counts++;
			}
			counts++;
		}
		if (swap == 1)
		{
			Swap(&mass[i], &mass[jmin]);
			swap = 0;
		}
	}
	return counts;
}

void PrintMass()
{
	for (int i = 0; i < nMass; i++)
		printf("%d ", mass[i]);
	printf("\n");
}

void PrintSingle(int possition)
{
   printf("Элемент - %d\nАдресс - %p\nЗначение - %d\n", possition, &mass[possition], mass[possition]);
}

int IsSorted () // 0 - Не сортирован, 1 - Сортирован
{
   for (int i = 0; i < nMass-1; i++)
   {
      if (mass[i] > mass[i+1])
         return 0;
   }
   return 1;
}

void StepSearch(int number)
{
	int counts= 0;
   for(int i = 0; i < nMass; i++)
	{
		if (mass[i] == number)
		{
			printf("Элемент - %d, Число - %d, Адресс - %p\n", i, mass[i], &mass[i]);
			counts++;
		}
	}
	if(counts > 0)
		printf("Значений не найдено :(\n");
}

void HalfSearch(int number)
{
	int min = 0;
	int max = nMass;
	int center = (min+max) / 2 + 0.5;
	while (number != mass[center] && center != max)
	{
		if (mass[center] > number)
			max = center;
		else min = center;
		center = (min + max) / 2 + 0.5;
	}
	if (number == mass[center])
		printf("Значение найдено !\nЭлемент - %d, Число - %d, Адресс - %p\n", center+1, mass[center], &mass[center]);
	else printf("Значение на найдено :(\n");
}

void RandomMass()
{
   int min = 0,max = 1;
   printf("Введите минимальное число: ");
   scanf("%d", &min);
   printf("Введите максимальное число: ");
   scanf("%d", &max);
	if(min > max)
	{
		printf("Не смущает, что минимум больше чем максимум ? Повторите ввод... \n");
		RandomMass();
	}
   Randomizer(min,max);
}

void Sort()
{
   int i, counts = 0;
	printf("Выберите сортировку:\n");
	printf("1 - Обычная сортировка 'Пузырьком'\n");
	printf("2 - Оптимизировання сортировка 'Пузырьком'\n");
	printf("3 - Сортировка выборкой\n");
	scanf("%d", &i);
   switch (i)
   {
      case 1:
         counts = BubbleSort();
         break;
      case 2:
         counts = BubbleSortOptimized();
         break;
      case 3:
         counts = ChoiseSort();
         break;
      default:
         printf("К сожалению значение не верное :(\n");
         break;
   }
      printf("\nШагов в сортировке(сложность) = %d\n", counts);
}

void Search()
{
   int number;
   printf("Введите значение, которое хотели бы найти: ");
   scanf("%d", &number);
   if(IsSorted() == 1)
      HalfSearch(number);
   else StepSearch(number);
}

void Menu()
{
	int i;
	printf("%s", "Меню:\n1 - Загрузить массив из 'load.txt'.\n");
	printf("%s", "2 - Сгенерировать случаные числа.\n");
   printf("%s", "3 - Найти необходимое значение.\n");
   printf("%s", "4 - Отсортировать список.\n");
	printf("%s", "0 - Выйти из программы.\n");
	scanf("%d", &i);
	switch (i)
	{
      case 0:
         printf("До свидания ! ;)\n");
			exited = 0;
         break;
		case 1:
			LoadMass();
			break;
		case 2:
			RandomMass();
			break;
		case 3:
         Search();
			break;
      case 4:
         Sort();
			break;
		default:
			printf("%s", "Вы ничего не выбрали\n");
			break;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));  // NOLINT
   do
   {
      PrintMass();
      Menu();
   } while (exited != 0);
	system("pause");
	return 0;
}
