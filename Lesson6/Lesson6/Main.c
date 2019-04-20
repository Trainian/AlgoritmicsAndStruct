/*
1.	
		С клавиатуры вводится строка символов:
	a.	Написать собственную функцию аналог strlen.
	b.	Вводится символ. Написать функцию, которая подсчитывает сколько раз символ входит в строку;
	c.	Написать программу, которая определяет, есть ли в строке гласные буквы;
	d.	*Написать программу, которая определяет, какая гласная буква встречается чаще всего;
	e.	**Предусмотреть, что некоторые гласные могут встречаться одинаково часто. В этом случае вывести сообщение, что нет наиболее часто встречающейся гласной.
2.	  
	a.  **Для двух строк напишите функцию, определяющую, является ли одна строка перестановкой другой. “МИРА=ИРМА”
    b.  **напишите утилиту, которая решает задачу принимая две строки в качестве параметров командной строки
3.	**Реализовать функцию, осуществляющую сжатие строки, на основе счётчика повторяющихся символов. Например, строка aabcccccaaa должна превратиться в a2b1c5a3. Если “сжатая” строка оказывается длиннее исходной, функция должна вернуть исходную строку.
4.	*Реализовать функцию void shift(char *str), которая будет циклически сдвигать строку вправо.
5.	*Даны два целочисленных массива, упорядоченных по возрастанию: А[n] и B[m]. Сформируйте массив C[n+m], состоящий из элементов массивов А и В, упорядоченный по возрастанию. Массивы A и B считать из файлов A.TXT и B.TXT.
6.	На вход программе подается математическое выражение. Проверить правильность расстановки скобок
	а) только для скобок ( и )
	б) *для различных скобок (,{,[,],},).
Достаточно решить 3 задачи. Старайтесь разбивать программы на подпрограммы. Переписывайте в начало программы условие и свою фамилию. Все программы сделать в одном решении. Для решения задач используйте неизменяемые строки (string)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MaxN 100

const char glasnie[] = {'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я'};

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
		printf("Слова являются перестановками ;)\n");
	}
	else printf("Слова не являются перестановками...\n");
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

	printf("Введите первое слово: ");
	gets(buffer1);
	printf("Второе слово для сравнения: ");
	gets(buffer2);
	printf("Длинна слова: %d\n", StringLength(str1));
	printf("Символ для поиска: ");
	scanf("%c", &symb);
	printf("'%c' - входит - %d раз(а)\n" ,symb ,HowManyChar(str1, symb));
	printf("Гласных в слове: %d\n", IsGlasnie(str1));
	IsPerestanovka(str1,str2);
	printf("Слово после сжатия, если было возможным: ");
	OptString(str1);

   printf("-----------END-----------\n");
	system("pause");
   return 0;
}