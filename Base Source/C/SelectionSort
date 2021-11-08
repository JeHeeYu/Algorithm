#include <stdio.h>

#define MINVALUE 100

void SelectionSort(int* array, int size);
void PrintArray(int* array, int size);

int main()
{
	int array[10] = { 41, 23, 12, 35, 78, 65, 43, 57, 92, 84 };

	SelectionSort(array, 10);
	PrintArray(array, 10);

	return 0;
}

void SelectionSort(int* array, int size)
{
	int temp, i, j, index;

	for (i = 0; i < size; i++)
	{
		int min = MINVALUE;
		for (j = i; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
}

void PrintArray(int* array, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", *(array + i));
	}
}
