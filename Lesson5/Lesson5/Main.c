/*
	1.	����������� �������������� ����������� ����������. 
		�������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
	2.	����������� ��������� ����������.
	3.	����������� �������� �������� ������ � ���� �������, ������� ���������� ��������������� ������. 
		������� ���������� ������ ���������� �������� ��� -1, ���� ������� �� ������.
	4.	*���������� ���������� �������� ��� ������ �� ���������� � �������� ��� �  ��������������� ���������� ���������.

	����������� ���� � ������� ������� ���������� �������: �� �����, ���������� �������, � ����������
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
	printf("������� ���-�� ��������� � �������, �� 1 �� 100\n");
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