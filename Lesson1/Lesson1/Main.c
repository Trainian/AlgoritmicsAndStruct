#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void task_6();
void task_7();
int task_7_color(int x, int y);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int choise = 0;
	printf(	"�������� �������:\n"
					"1- ������ ����� ����\n"
					"2- ������������ �� 4-� �����\n"
					"3- ����� ����������\n"
					"4- ���������� ������ ����������� ���������\n"
					"5- ���������� ��������� ������ �� ��� ������\n"
					"6- ���������� ��������� ��� ��������\n"
					"7- ���������� �� �����, ����������� � ������ �����\n");
	scanf("%i", &choise);
	switch (choise)
	{
	case 1:
		task_1();
		break;
	case 2:
		task_2();
		break;
	case 3:
		task_3();
		break;
	case 4:
		task_4();
		break;
	case 5:
		task_5();
		break;
	case 6:
		task_6();
		break;
	case 7:
		task_7();
		break;

	default:
		printf("� � ���� ��� �� ����� :(");
		break;
	}
	system("pause");
	return 0;
}

/*	
	������ ��� � ���� ��������.  ���������� � ������� ������ ����� ���� �� �������
	I=m/(h*h); ��� m-����� ���� � �����������, h - ���� � ������.	
 */
void task_1()
{
	float m, h = 0;
	printf("---������ ����� ����---\n");
	printf("������� ��� (� �����������):\n");
	scanf("%f", &m);
	printf("������� ���� (� ������):\n");
	scanf("%f", &h);
	float answer = m / (h*h);
	printf("������ ����� ����, ��� ����: %.2f, �����: %.2f = %.2f\n", m, h, answer);
}

/*
	����� ������������ �� ������� �����. ������� �� ������������.
 */
void task_2()
{
	int a, b, c, d = 0;
	printf("---������������ �����---\n");
	printf("%s", "���������������, ������� 4-� ������������� �����\n");
	scanf("%i", &a);
	scanf("%i", &b);
	scanf("%i", &c);
	scanf("%i", &d);
	if (a > b)
	{
		b = a;
	}
	if (c > d)
	{
		d = c;
	}
	if (b > d)
	{
		d = b;
	}
	printf("������������ ��������: %i\n", d);
}

/*
	�������� ��������� ������ ���������� ���� ������������� ����������: 
	a. � �������������� ������� ����������; 
	b. *��� ������������� ������� ����������.
 */
void task_3()
{
	int a, b;
	printf("---����� ���� ��������---\n");
	printf("��������������� ������� ��� ������������� ��������\n");
	scanf("%i", &a);
	scanf("%i", &b);
	printf("������ ��������: %.i, ������ ��������: %.i\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("����� ������, ������ ��������: %.i, ������ ��������: %.i\n", a, b);
}

/*
	�������� ��������� ���������� ������ ��������� ����������� ���������.
 */
void task_4()
{
	float a, b, c, x;
	printf("%s", "������� �������� 'a' : ");
	scanf("%f", &a);
	printf("%s", "������� �������� 'b' : ");
	scanf("%f", &b);
	printf("%s", "������� �������� 'c' : ");
	scanf("%f", &c);
	if ((b*b - 4 * a*c) >= 0)
	{
		x = (-1 * b + sqrt(b*b - 4 * a*c)) / (2 * a);
		printf("������ ������ - %.2lf\n", x);
		x = (-1 * b - sqrt(b*b - 4 * a*c)) / (2 * a);
		printf("������ ������ - %.2lf\n", x);
	}
	else { printf("������������ ������ 0, ����� ��������������.\n"); }
}

/*
	� ���������� �������� ����� ������. ��������� ����������, � ������ ������� ���� �� ���������. 
 */
void task_5()
{
	int a;
	printf("---����� ������---\n");
	printf("������� ����� ������\n");
	scanf("%i", &a);
	if (a >= 0 && a <= 12)
	{
		if (a >= 12 || a <= 2)
		{
			printf("%i - ������ �����!\n", a);
		}

		if (a >= 3 && a <= 5)
		{
			printf("%i - �������� �����!\n", a);
		}

		if (a >= 6 && a <= 8)
		{
			printf("%i - ������ �����!\n", a);
		}

		if (a >= 9 && a <= 11)
		{
			printf("%i - ������� �����!\n", a);
		}

	}
	else { printf("����� 12 �������...\n"); }
}

/*
	������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����. 
 */
void task_6()
{
	int age;
	printf("---������� � ���������� ('���','����','���')---\n");
	printf("������� ������� � ��������� �� 0 �� 150 ���\n");
	scanf("%i", &age);
	if (age >= 0 && age <= 150)
	{
		int newAge;
		newAge = age % 10;

		if (newAge == 1)
			printf("%i ���\n", age);
		else if (newAge >= 2 && newAge <= 4)
			printf("%i ����\n", age);
		else
			printf("%i ���\n", age);
	}
	else { printf("���-�� �� ��� � ���������\n"); }
}

/*
	� ���������� �������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2). ��������� ����������, ��������� �� � ���� � ������ ����� ��� ���. 
 */
void task_7()
{
	int x1,y1,x2,y2;
	int dot1, dot2;
	printf("---���� ��������� �� ��������� �����---\n");
	printf("������� ���������� � ������������� �������� �� 1 �� 8\n");
	printf("���������� �1 - ");
	scanf("%i",&x1);
	printf("���������� y1 - ");
	scanf("%i",&y1);
	printf("���������� �2 - ");
	scanf("%i",&x2);
	printf("���������� y2 - ");
	scanf("%i",&y2);
	printf("���� ������� �������� - ");
	dot1 = task_7_color(x1,y1);
	printf("���� ������� �������� - ");
	dot2 = task_7_color(x2,y2);
	if (x1 >= 0 && x1 <= 8 &&
		y1 >= 0 && y1 <= 8 &&
		x2 >= 0 && x2 <= 8 &&
		y2 >= 0 && y2 <= 8 ) 
	{
		if(dot1 == dot2)
		{
			printf("��� �������� ����� ���� ���� !\n");
		}
		else{ printf("�������� ������ ������\n"); }
	}
	else { printf("������� ��������� ��� ���������\n"); }
	}

/*
	��������� ����, ����� ���������� 'x' � 'y', ��� 1 - ������, 0 - �����.
*/
int task_7_color(int x, int y)
{
	const int temp = (x + y) % 2;
	if(temp == 0)
	{
		printf("������\n");
		return 1;
	}
	else
	printf("�����\n");
	return 0;
}