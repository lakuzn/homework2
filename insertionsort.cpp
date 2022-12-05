#include<iostream>  
#include <math.h>
using namespace std;

void insertionsort(int* arr, int size) {
	for (int i = 1; i < size; i++) //�� �������� �� ������� �������� � ���������� � ����������. ����������� �������� ���������� � ������ ��������� ������� � ���������� ��������������� ������.
	{
		int temp = arr[i]; 
		int j = i - 1;
		while (j >= 0 && temp <= arr[j]) //���� j>=0 � ������ ������� ������� ������ �����������, ������ �� �������.
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

int main() { //����, � ������� �� ������ ������, ��������� insertionsort � ������� ��������������� ������
	setlocale(LC_ALL, "RUS");
	cout << "������� ������ �������." << endl;
	int size;
	cin >> size;
	int* arr = new int[size];
	arr[0] = 5;
	cout << "������� ������� �������." << endl;
	for (int i = 0; i < size; i++) cin >> arr[i];
	insertionsort(arr, size);
	cout << "��������������� ������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}