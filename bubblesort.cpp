#include <iostream>
#include <math.h>
using namespace std;

void swap(double a, double b) { //������� ������ �������� ����������
	double x = a;
	a = b;
	b = x;
}

void bubblesort(int* arr, int size) { //��� bubblesort
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]){ //���� j-�� ��-� ������� ������, ��� j+1, �� �� �� �������
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()  { //����, � ������� �� �������� ������� bubblesort, ������ � ����� ������
	setlocale(LC_ALL, "RUS");
	cout << "������� ������ �������." << endl;
	int size;
	cin >> size;
	int* arr = new int[size];
	arr[0] = 5;
	cout << "������� ������� �������." << endl;
	for (int i = 0; i < size; i++) cin >> arr[i];
	bubblesort(arr, size);
	cout << "��������������� ������:" << endl;
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	delete[] arr; //����������� ������, ������� �������� ��� ������������� �������
	arr = nullptr;
}