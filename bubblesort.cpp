#include <iostream>
#include <math.h>
using namespace std;

void swap(double a, double b) { //функция обмена значений переменных
	double x = a;
	a = b;
	b = x;
}

void bubblesort(int* arr, int size) { //сам bubblesort
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]){ //если j-ый эл-т массива больше, чем j+1, то мы их свапаем
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()  { //мейн, в котором мы вызываем функцию bubblesort, вводим и вывод массив
	setlocale(LC_ALL, "RUS");
	cout << "Введите размер массива." << endl;
	int size;
	cin >> size;
	int* arr = new int[size];
	arr[0] = 5;
	cout << "Введите элемент массива." << endl;
	for (int i = 0; i < size; i++) cin >> arr[i];
	bubblesort(arr, size);
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	delete[] arr; //освобождаем память, которую выделяли для динамического массива
	arr = nullptr;
}