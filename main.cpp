#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    unsigned r, c;
	cout << "rows = ";
	cin >> r;
	cout << "cols = ";
	cin >> c;
	int ** arr = NULL;
	arr = new int*[r];
	for (size_t i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}

	fillArray(arr, r, c);
	printArray(arr, r, c);

	cout << "Element " << arr[0][1]
		<< " is "
		<< (CheckMainDiag(arr, r, c, arr[0][1]) ? "" : "not ")
		<< "part of the main diagonal.\n";

	cout << "Element " << arr[1][0]
		<< " is "
		<< (CheckSecondDiag(arr, r, c, arr[1][0]) ? "" : "not ")
		<< "part of the second diagonal.\n";

	unsigned menu;
	cout << "Please select an option: \n"
		<< "1 - to change elements if they are part of main diagonal\n"
		<< "2 - to change elements if they are part of second diagonal\n"
		<< "3 - to change elements if they are not part of both diagonals\n"
		<< "4 - to change elements if they are less or equal to the avareage\n";
	cin >> menu;
	switch (menu)
	{
        case 1: ChangeArray(CheckMainDiag, arr, r, c); break;
        case 2: ChangeArray(CheckSecondDiag, arr, r, c); break;
        case 3: ChangeArray(CheckNotBothDiag, arr, r, c); break;
        case 4: ChangeArray(CheckAvg, arr, r, c); break;
	}

	printArray(arr, r, c);

	for (size_t i = 0; i < r; i++)
		delete[] arr[i];

	delete[] arr;
	arr = NULL;
    return 0;
}
