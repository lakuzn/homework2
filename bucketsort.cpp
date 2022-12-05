#include <iostream>
#include <math.h>
using namespace std;

int findmax(int arr[], int size) {
    int cnt = 0;
    int max = arr[0];
    for (int i = 1; i < size; i++) //находим максимум в массиве
    {
        if (arr[i] > max)
            max = arr[i];
    }
    while (max > 0) //находим его разряд, чтобы разложить каждый разряд в свой bucket
    {
        cnt++;
        max = max / 10;
    }
    return cnt;
}

void bucketsort(int arr[], int* bucket[], int n)
{
    static int j[10], d = 1; 
    int c, k;
    c = findmax(arr, n); // находим максимум массива
    for (int m = 0; m < c; m++)
    {
        for (int i = 0; i < 10; i++) //разбираем массив на бакеты каждого разряда. 
            j[i] = 0;
        for (int i = 0; i < n; i++)
        {
            k = (arr[i] / d) % 10;
            bucket[k][j[k]] = arr[i]; //распределяем бакеты.
            j[k]++;
        }

        int l = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < j[i]; k++) //сортируем каждый бакет отдельно
            {
                arr[l] = bucket[i][k];
                l++;
            }
        }
        d *= 10;
    }
}
int main() //мейн, в котором мы вводим массив, применяем bucketsort и выводим отсортированный массив.
{
    setlocale(LC_ALL, "RUS");
    int size;
    int* bucket[10];
    cout << "Введите размер массива." << endl;
    cin >> size;
    int* arr = new int[size + 1];
    for (int i = 0; i < 10; i++)
        bucket[i] = new int[size];
    cout << "Введите элемент массива." << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    bucketsort(arr, bucket, size);
    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    delete[] arr; //освобождаем память, которую выделяли для динамического массива
	arr = nullptr;
    return 0;
}
