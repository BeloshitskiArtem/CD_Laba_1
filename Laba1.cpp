#include "DinamikArray.h"

void Help()
{
	cout << "Для создания и инициализаци полей, введите 1." << endl;
	cout << "Для удаления элемента из массива, введите 2." << endl;
	cout << "Для вставки элеента в начало, введите 3." << endl;
	cout << "Для вставки элемента в конец, введите 4." << endl;
	cout << "Для вставки после определённого элемена, нажмите 5." << endl;
	cout << "Для сортировки массива, введите 6." << endl;
	cout << "Для линейного поиска в массиве, введите 7." << endl;
	cout << "Для бинарного поиска, введите 8." << endl;
	cout << "Для вывода массива на экран, введите 9." << endl;
	cout << "Для остановки программы, введите 0." << endl;
}

void AnalizeOperationCode(int operationCode, DinamikArray* array)
{
	switch (operationCode)
	{
	case 1:
		СreateArray(array);
		break;
	case 2:
		DeleteOnesElementOfArray(array);
		break;
	case 3:
		InPutInBeginArray(array);
		break;
	case 4:
		InPutInEndArray(array);
		break;
	case 5:
		InsertionByIndex(array);
		break;
	case 6:
		InsertionSort(array);
		break;
	case 7:
		LineSkan(array);
		break;
	case 8:
		BineSkan(array);
		break;
	case 9:
		ShowArray(array);
		break;
	default:
		Help();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	DinamikArray* newArray = new DinamikArray;

	int operationCode = 1;
	do
	{
		AnalizeOperationCode(operationCode, newArray);
		Help();
		cin >> operationCode;
	} while (!(operationCode == 0 || operationCode < 0 || operationCode > 9));

	return 0;
}