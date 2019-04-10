#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERM_WORD "end"
#define SIZE 2

int main(int argc, char *argv[])
{
    printf("\n----------START----------\n");
	int word_counts = 0;
	char buffer[10];
	unsigned size = SIZE;
	unsigned length;

	char **words = malloc(SIZE * sizeof(char*));
	do
	{
		printf("%d - ", word_counts);
		scanf("%9s", buffer);

		if(!strcmp(TERM_WORD,buffer))
		{			
			break;
		}

		if(word_counts >= size)
		{
			size += SIZE;
			words = realloc(words, size * sizeof(char*));
		}

		length = strlen(buffer);
		words[word_counts] = malloc(length * sizeof(char) + 1);
		strcpy(words[word_counts], buffer);
		word_counts++;
	} while (1);
	puts("---WORDS-->");
	for(int i = 0; i < word_counts; i++)
		printf("%d - %s\n", i, words[i]);

    printf("\n-----------END-----------\n");
    return 0;
}