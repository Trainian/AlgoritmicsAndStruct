/*
	1.	����������� �������������� ����������� ����������. 
		�������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
	TODO: DONE 0.	����� �������� � ����� ��� ��������� ��������� �����.
	TODO: DONE 1.	����������� ����� �������� � ����������� �������.
	TODO: 2.	����������� ��������� ����������.
	TODO: DONE 3.	����������� �������� �������� ������ � ���� �������, ������� ���������� ��������������� ������. ������� ���������� ������ ���������� �������� ��� -1, ���� ������� �� ������.
	TODO: DONE 4.	*���������� ���������� �������� ��� ������ �� ���������� � �������� ��� �  ��������������� ���������� ���������.
	TODO: DONE 5. ����������� ���� � ������� ������� ���������� �������: �� �����, ���������� �������, � ����������
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define MaxN 100 // �������� ��������

int mass[MaxN]; // ������, �������� ��������� MaxN
int nMass; // ���-�� ��������� � �������
int exited = 1; // 0 - ����� �� ���������
FILE *f; // �������� � �����

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
   printf("%s %d \n","������� ���-�� ��������� � �������, �� 1 ��", MaxN);
	scanf("%d", &nMass);
	if (nMass < 1 || nMass > MaxN)
	{
		printf("%s", "������� �� ���������� ��������, �������� ����.\n");
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
   printf("������� - %d\n������ - %p\n�������� - %d\n", possition, &mass[possition], mass[possition]);
}

int IsSorted () // 0 - �� ����������, 1 - ����������
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
			printf("������� - %d, ����� - %d, ������ - %p\n", i, mass[i], &mass[i]);
			counts++;
		}
	}
	if(counts > 0)
		printf("�������� �� ������� :(\n");
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
		printf("�������� ������� !\n������� - %d, ����� - %d, ������ - %p\n", center+1, mass[center], &mass[center]);
	else printf("�������� �� ������� :(\n");
}

void RandomMass()
{
   int min = 0,max = 1;
   printf("������� ����������� �����: ");
   scanf("%d", &min);
   printf("������� ������������ �����: ");
   scanf("%d", &max);
	if(min > max)
	{
		printf("�� �������, ��� ������� ������ ��� �������� ? ��������� ����... \n");
		RandomMass();
	}
   Randomizer(min,max);
}

void Sort()
{
   int i, counts = 0;
	printf("�������� ����������:\n");
	printf("1 - ������� ���������� '���������'\n");
	printf("2 - ��������������� ���������� '���������'\n");
	printf("3 - ���������� ��������\n");
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
         printf("� ��������� �������� �� ������ :(\n");
         break;
   }
      printf("\n����� � ����������(���������) = %d\n", counts);
}

void Search()
{
   int number;
   printf("������� ��������, ������� ������ �� �����: ");
   scanf("%d", &number);
   if(IsSorted() == 1)
      HalfSearch(number);
   else StepSearch(number);
}

void Menu()
{
	int i;
	printf("%s", "����:\n1 - ��������� ������ �� 'load.txt'.\n");
	printf("%s", "2 - ������������� �������� �����.\n");
   printf("%s", "3 - ����� ����������� ��������.\n");
   printf("%s", "4 - ������������� ������.\n");
	printf("%s", "0 - ����� �� ���������.\n");
	scanf("%d", &i);
	switch (i)
	{
      case 0:
         printf("�� �������� ! ;)\n");
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
			printf("%s", "�� ������ �� �������\n");
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
