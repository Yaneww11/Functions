#include <iostream>
#include <stdlib.h>
#include "functions.h"


int fillArray(int**arr , unsigned r, unsigned c ) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			arr[i][j] = rand() % 24 - 5;
	}

	return 0;
}
int printArray(int**arr, unsigned r, unsigned c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			std::cout << arr[i][j] << "\t\t";

		std::cout << "\n";
	}
	return 0;
}
bool CheckMainDiag(int** arr, unsigned r, unsigned c, int elem) {
	unsigned end = r < c ? r : c;
	for (size_t i = 0; i < end; i++)
	{
		if (arr[i][i] == elem)
            return true;
	}
	return false;
}

bool CheckSecondDiag(int** arr, unsigned r, unsigned c, int elem) {
	unsigned end = r < c ? r : c;
	for (size_t i = 0; i < end; i++)
	{
		if (arr[i][c-1-i] == elem)
            return true;
	}
	return false;
}


bool CheckNotBothDiag(int** arr, unsigned r, unsigned c, int elem) {
	if (CheckMainDiag(arr, r, c, elem)
		|| CheckSecondDiag(arr, r, c, elem)) return false;
	return true;
}

bool CheckAvg(int** arr, unsigned r, unsigned c, int elem) {
	int sum = 0;
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			sum += arr[i][j];
		}
	}
	sum /= (r * c);
	return (elem <= sum);
}


int ChangeArray(typePred fun, int** arr, unsigned r, unsigned c) {
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			if ((*fun)(arr, r, c, arr[i][j]))
				arr[i][j] += i + j;
			else
				arr[i][j] -= i;
		}
	}
	return 0;
}
