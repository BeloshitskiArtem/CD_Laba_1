#include "DinamikArray.h"
#define GrowthFactor 2;

int Input(string iputInformation, int& value)
{
	cout << iputInformation << endl;
	cin >> value;
	cout << endl;
	return value;
}

void Resize(DinamikArray* array)
{
	array->Length = array->Capacite;
	array->Capacite = array->Capacite * GrowthFactor;

	int* newArray = new int[array->Capacite];

	for (int i = 0; i < array->Length; i++)
	{
		newArray[i] = array->Array[i];
	}

	//TODO: Çà÷åì?
	delete [] array->Array;
	array->Array = newArray;
}

void ÑreateArray(DinamikArray* array)
{
	array->Length = Input("Input Length of array: ", array->Length);
		array->Capacite = Input("Input Capacite of array: ", array->Capacite);

	array->Array = new int[array->Capacite];
	for (int i = 0; i < array->Length; i++)
	{
		array->Array[i] = 1 + rand() % 20;
	}
}

void ShowArray(DinamikArray* array)
{
	for (int i = 0; i < array->Capacite; i++)
	{
		cout << array->Array[i] << '\t';
	}
	cout << endl;
}

void InPutInBeginArray(DinamikArray* array)
{
	int beginElement = Input("Input element in begin: ", beginElement);

	if (array->Capacite == array->Length)
	{
		Resize(array);
	}

	for (int i = 0; i < array->Length+1; i++)
	{
		swap(array->Array[i], beginElement);
	}
	array->Length += 1;
}


void DeleteOnesElementOfArray(DinamikArray* array)
{
	int numberElementTemp = Input("Enter number element delete: ", numberElementTemp);

	for (int i = 0; i < array->Length; i++)
	{
		if(i >= numberElementTemp)
		{
			array->Array[i] = array->Array[i + 1];
		}
	}
	array->Length -= 1;
}

void InPutInEndArray(DinamikArray* array)
{
	int endElement = Input("Input element in end: ", endElement);

	if (array->Capacite == array->Length)
	{
		Resize(array);
	}

	array->Array[array->Length] = endElement;
	array->Length += 1;
}

void InsertionSort(DinamikArray* array)
{
	int temp;
	int	itemPredidushiyIndex;
	for (int counter = 1; counter < array->Length; counter++)
	{
		temp = array->Array[counter];
		itemPredidushiyIndex = counter - 1;
		while (itemPredidushiyIndex >= 0 && array->Array[itemPredidushiyIndex] > temp)
		{
			array->Array[itemPredidushiyIndex + 1] = array->Array[itemPredidushiyIndex];
			array->Array[itemPredidushiyIndex] = temp;
			itemPredidushiyIndex--;
		}
	}
}

void LineSkan(DinamikArray* array)
{
	int key = Input("Input Key: ", key);
	int bufer = 0;

	int* buferArray = new int[array->Length];

	for (int i = 0; i < array->Length; i++)
	{
		if (array->Array[i] == key)
		{ 
			buferArray[bufer] = i;
			bufer++;
		}
	}

	if (bufer != 0)
	{ 
		for (int i = 0; i < bufer; i++)
		{
			cout << "key " << key << " in:  " << buferArray[i] << endl; 
		}
	}
	else
	{
		cout << "don't found " << key << " in array, sorry!";
	}
	delete[] buferArray;
}

void BineSkan(DinamikArray* array)
{
	InsertionSort(array);
	ShowArray(array);
	
	int searchValue = Input("Input number for skan: ", searchValue);
	
	int indexLeftBoundary = 0;
	int indexRightBoundary = array->Length - 1;
	while (indexLeftBoundary <= indexRightBoundary)
	{
		int indexMidValue = (indexLeftBoundary + indexRightBoundary) / 2;
		if (array->Array[indexMidValue] == searchValue)
		{
			cout << "Index of element: " << indexMidValue << endl;
			break;
		}
		else if (searchValue > array->Array[indexMidValue])
		{
			indexLeftBoundary = indexMidValue + 1;
		}
		else
		{
			indexRightBoundary = indexMidValue - 1;
		}
	}
}

void InsertionByIndex(DinamikArray* array)
{
	int value = Input("Input element: ", value);
	int index = Input("Input the index of the element to unsert: ", index);

	if (index < 0 || index > array->Length+2)
	{
		cout << "Inapporopriate index" << endl;
	}

	else
	{
		if (array->Capacite == array->Length)
		{
			Resize(array);
		}
		
		for (int i = index; i < array->Length+1; i++)
		{
			swap(value, array->Array[i]);
		}
	}
}

