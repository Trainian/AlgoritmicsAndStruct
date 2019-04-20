/*
1.	
		� ���������� �������� ������ ��������:
	a.	�������� ����������� ������� ������ strlen.
	b.	�������� ������. �������� �������, ������� ������������ ������� ��� ������ ������ � ������;
	c.	�������� ���������, ������� ����������, ���� �� � ������ ������� �����;
	d.	*�������� ���������, ������� ����������, ����� ������� ����� ����������� ���� �����;
	e.	**�������������, ��� ��������� ������� ����� ����������� ��������� �����. � ���� ������ ������� ���������, ��� ��� �������� ����� ������������� �������.
2.	  
	a.  **��� ���� ����� �������� �������, ������������, �������� �� ���� ������ ������������� ������. �����=�����
    b.  **�������� �������, ������� ������ ������ �������� ��� ������ � �������� ���������� ��������� ������
3.	**����������� �������, �������������� ������ ������, �� ������ �������� ������������� ��������. ��������, ������ aabcccccaaa ������ ������������ � a2b1c5a3. ���� �������� ������ ����������� ������� ��������, ������� ������ ������� �������� ������.
4.	*����������� ������� void shift(char *str), ������� ����� ���������� �������� ������ ������.
5.	*���� ��� ������������� �������, ������������� �� �����������: �[n] � B[m]. ����������� ������ C[n+m], ��������� �� ��������� �������� � � �, ������������� �� �����������. ������� A � B ������� �� ������ A.TXT � B.TXT.
6.	�� ���� ��������� �������� �������������� ���������. ��������� ������������ ����������� ������
	�) ������ ��� ������ ( � )
	�) *��� ��������� ������ (,{,[,],},).
���������� ������ 3 ������. ���������� ��������� ��������� �� ������������. ������������� � ������ ��������� ������� � ���� �������. ��� ��������� ������� � ����� �������. ��� ������� ����� ����������� ������������ ������ (string)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MaxN 100

const char glasnie[] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};

int StringLength (char* mass)
{
	int i = 0;
	do
	{
		if (mass[i] == '\0')
		{
			break;
		}
		i++;
	} while (1);
	return i;
}

int HowManyChar (char* mass, char symb)
{
	int i = 0,j = 0;
	do
	{
		if (mass[i] == '\0')
		{
			break;
		}
		if (mass[i] == symb)
			j++;
		i++;
	} while (1);
	return j;
}

int IsGlasnie (char* mass)
{
	int i = 0,j = 0;
	do
	{
		if(mass[i] == '\0')
		{
			break;
		}
		for(int k = 0; k < 10; k++)
		{
			if(mass[i] == glasnie[k])
				j++;
		}
		i++;
	} while (1);
	return j;
}

void IsPerestanovka (char* mass1, char* mass2)
{
	int i,j;
	int lng = StringLength(mass2);
	if (StringLength(mass1) == lng)
	{
		for(i=0, j=lng; i < lng/2; i++, j--)
		{
			if(mass1[i] != mass2[j])
				break;
		}
		printf("����� �������� �������������� ;)\n");
	}
	else printf("����� �� �������� ��������������...\n");
}

void OptString (char* mass)
{
	char optString[MaxN];
	char last = NULL;
	int i = 0, j = 0, k = 1;
	do
	{
		if(mass[i] == last)
		{
			k++;
		}
		else if(k > 1)
		{
 			optString[j] = '0' + k;
			k = 1;
			j++;
			i--;
		}
		else 
		{
			optString[j] = mass[i];
			last = optString[j];
			j++;
		}
		if (mass[i] == '\0')
		{
			break;
		}
		i++;
	} while (1);
	optString[j] = '\0';
	puts(optString);
}

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    printf("\n----------START----------\n");

	char *str1, *str2;
	char buffer1[MaxN], buffer2[MaxN], symb;
	str1 = buffer1;
	str2 = buffer2;

	printf("������� ������ �����: ");
	gets(buffer1);
	printf("������ ����� ��� ���������: ");
	gets(buffer2);
	printf("������ �����: %d\n", StringLength(str1));
	printf("������ ��� ������: ");
	scanf("%c", &symb);
	printf("'%c' - ������ - %d ���(�)\n" ,symb ,HowManyChar(str1, symb));
	printf("������� � �����: %d\n", IsGlasnie(str1));
	IsPerestanovka(str1,str2);
	printf("����� ����� ������, ���� ���� ���������: ");
	OptString(str1);

   printf("-----------END-----------\n");
	system("pause");
   return 0;
}