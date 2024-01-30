#include <stdio.h>

/**
 * findMaximum - finds max value in array
 * @numbersArray: input array
 *
 * Return: max value found
 */

int findMaximum(int *numbersArray)
{
	int size = sizeof(numbersArray) / sizeof(numbersArray[0]);
	int max = numbersArray[0];
	int i;

	for (i = 0; i < size; i++)
	{
		if (numbersArray[i] > max)
		{
			max = numbersArray[i];
		}
	}
	return (max);
}

int main(void)
{
	int array[6] = {2, 14, 55, 105, 2560, 2};
	int maxNum = findMaximum(array);

	printf("%d\n", maxNum);

	return (0);
}
