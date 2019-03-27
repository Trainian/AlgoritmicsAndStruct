/*
1.	������� ������ �� 100 ���������. �������� ���������, ������� �������� ������� ���
	a.	����� ������� � ����������;
	b.	��������� ������ ���������� �������;
	c.	�������� ����� ���������;
	d.	�������� �������� �������������� ���������;
	e.	���������� ������ ������� ��������, ������� ����������� ���������� �� �������� ���������������;
	f.	������� ������������ ����� � �������;
	g.	*��������� ������ �� �����. � ����� ������ ������ ���� ���-�� ��������� �������;
	h.	**������� ��� ������ ���������, ������� ����������� ���������� �� �������� ��������������� �������;
	i.	������� ������ ������� � ���� �������, � ������� ���������� ������.
	j.	**���������� ������� (��� ��� ���������) � �������������� ���������� ����������.
2.	*��������� ������ ������� ��� ����������� �������
3.	**����������� �������� ������� �����������.
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
	printf("����� ���������: %i\n", summ(mass));
	printf("������� ��������������: %.2f\n", averageMass(mass));
	printf("�����, ������� ����������� ���������� �� �������� ���������������: %i\n", averageDiff(mass));
	printf("������ ������ � ����� 'data.txt': \n");
	readFile(mass);

	system("pause");
}

void enterMass (int *mass)
{
	int a = 0;
	printf("������� ������ � ���������� ��� ��������� �������������:\n");
	printf("1 - ���� � ������.\n2 - �������������� ����������\n");
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