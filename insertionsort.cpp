#include<iostream>  
#include <math.h>
using namespace std;

void insertionsort(int* arr, int size) {
	for (int i = 1; i < size; i++) //мы начинаем со второго элемента и сравниваем с предыдущим. Аналогичные действия производим с каждым элементов массива и постепенно отсортировываем массив.
	{
		int temp = arr[i]; 
		int j = i - 1;
		while (j >= 0 && temp <= arr[j]) //пока j>=0 и взятый элемент массива меньше предыдущего, меняем их местами.
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

int main() { //мейн, в котором мы вводим массив, применяем insertionsort и выводим отсортированный массив
	setlocale(LC_ALL, "RUS");
	cout << "Введите размер массива." << endl;
	int size;
	cin >> size;
	int* arr = new int[size];
	arr[0] = 5;
	cout << "Введите элемент массива." << endl;
	for (int i = 0; i < size; i++) cin >> arr[i];
	insertionsort(arr, size);
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] arr; //освобождаем память, которую выделяли для динамического массива
	arr = nullptr;
	return 0;
}
