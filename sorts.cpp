#include <iostream>
#include <ctime>
#define r 0;

using namespace std;

//RandFill is filling an array with random numbers
void RandFill(int* arr, int size) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 50;
}

//SimpleFill is filling an array in descending order of numbers
void SimpleFill(int* arr, int size) {
	int n = size;
	for (int i = 0; i < size; i++) {
		arr[i] = n;
		n--;
	}
}

//Show is displaying the current state of an array
void Show(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//Default select sort
void SelectSort(int* arr, int size) {
	
	int tmp;
	int repeats = 0;

	for (int i = 0; i < size; ++i)
	{
		int pos = i;
		tmp = arr[i];
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < tmp)
			{
				pos = j;
				tmp = arr[j];
			}
		}
		cout << "State[" << repeats << "]: ";
		Show(arr, size);
		repeats++;
		arr[pos] = arr[i];
		arr[i] = tmp;
	}
}

//Default bubble sort
void BubbleSort(int* arr, int size) {

	int tmp;
	int repeats = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {				
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		repeats++;
		cout << "State[" << repeats << "]: ";
		Show(arr, size);
	}
}

//Default shaker sort
void ShakerSort(int* arr, int size) {
	int repeats = 0,
		left = 0,
		right = size - 1,
		tmp;
	bool flag = true;
	
	while ((left < right) && flag) {
		
		flag = false;

		for (int i = left; i < right; i++)
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = true;
			}

		repeats++;
		cout << "State[" << repeats << "]: ";
		Show(arr, size);

		right--;

		for (int i = right; i > left; i--)
			if (arr[i - 1] > arr[i]) {
				tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
				flag = true;
			}

		left++;

		repeats++;
		cout << "State[" << repeats << "]: ";
		Show(arr, size);

	}
}

//Default comb sort
void CombSort(int* arr, int size) {
	
	double k = 1.2473309;
	int gap = size,
		tmp,
		j,
		repeats = 0;
	bool flag = true;

	while (gap > 1 || flag) {
		

		cout << gap << " / " << k << endl;
		gap = (int)(gap / k);

		cout << "gap = " << gap << endl;
		cout << "len = " << size - gap << endl;
		
		if (gap < 1) {
			gap = 1;
		}

		flag = false;
		
		for (int i = 0; i < size - gap; i++) {
			
			j = i + gap;
			
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				flag = true;
			}
		}
		repeats++;
		cout << "State[" << repeats << "]: ";
		Show(arr, size);

	}
}

void Show(int* arr) {
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//Default quick sort
void QuickSort(int* arr, int left, int right) {

	int i = left, j = right;
	int temp, pivot = arr[(left + right) / 2];
	cout << pivot << endl;
	while (i <= j) {
		
		while (arr[i] < pivot) 
			i++;
		
		while (arr[j] > pivot) 
			j--;

		if (i <= j) {
			
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

			i++;
			j--;
		}

	};

	cout << "State[]: ";
	Show(arr);


	if (left < j) 
		QuickSort(arr, left, j);
	if (i < right) 
		QuickSort(arr, i, right);
}

//Standart sort shows all sorting steps
void StandartSort(int size) {

	int* arr1 = new int[size];
	int* arr2 = new int[size];
	int* arr3 = new int[size];
	int* arr4 = new int[size];
	int* arr5 = new int[size];
	
	RandFill(arr1, size);

	for (int i = 0; i < size; i++)
		arr2[i] = arr1[i];

	for (int i = 0; i < size; i++)
		arr3[i] = arr1[i];

	for (int i = 0; i < size; i++)
		arr4[i] = arr1[i];
	
	for (int i = 0; i < size; i++)
		arr5[i] = arr1[i];

    cout << "Bubble Sort\nOriginal: ";
	Show(arr1, size);
	cout << endl;

	BubbleSort(arr1, size);

	cout << "\nOutcome: ";
	Show(arr1, size);
	cout << endl;

	cout << "Select Sort\nOriginal: ";
	Show(arr2, size);
	cout << endl;

	SelectSort(arr2, size);

	cout << "\nOutcome: ";
	Show(arr2, size);
	cout << endl;

	cout << "Shaker Sort\nOriginal: ";
	Show(arr3, size);
	cout << endl;

	ShakerSort(arr3, size);

	cout << "\nOutcome: ";
	Show(arr3, size);
	cout << endl;

	cout << "Comb Sort\nOriginal: ";
	Show(arr4, size);
	cout << endl;

	CombSort(arr4, size);

	cout << "\nOutcome: ";
	Show(arr4, size);
	cout << endl;

	cout << "Quick Sort\nOriginal: ";
	Show(arr5, size);
	cout << endl;

	QuickSort(arr5, 0, size - 1);

	cout << "\nOutcome: ";
	Show(arr5, size);
	cout << endl;

}

int main() {

	srand(time(0));

	int size = 10;

	StandartSort(size);
	
	return 0;
}
