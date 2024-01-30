#include <stdio.h>

/**
 * countCharacters - finds the length of a string
 * @word: input string
 *
 * Return: the length of the string
 */

int countCharacters(char *word)
{
	int len;
	
	for (len = 0; word[len] != '\0'; len++);
	
	return (len);
}

void main(void)
{
	int numChars;

	numChars = countCharacters("onomatopeia");
	printf("%d\n", numChars);

}
