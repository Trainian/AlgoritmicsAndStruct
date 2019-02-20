#include  <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

void main ()
{
	int a;
	printf("%s", "Hello STRING\n");
	printf("enter Number 'a'\n");
	scanf_s("%i", &a);
	printf("'a': Value - %i, Adress - %p\n", a, &a);
	system("pause");
}