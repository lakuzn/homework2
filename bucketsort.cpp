#include <iostream>
#include <math.h>
using namespace std;

int findmax(int arr[], int size) {
    int cnt = 0;
    int max = arr[0];
    for (int i = 1; i < size; i++) //������� �������� � �������
    {
        if (arr[i] > max)
            max = arr[i];
    }
    while (max > 0) //������� ��� ������, ����� ��������� ������ ������ � ���� bucket
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
    c = findmax(arr, n); // ������� �������� �������
    for (int m = 0; m < c; m++)
    {
        for (int i = 0; i < 10; i++) //��������� ������ �� ������ ������� �������. 
            j[i] = 0;
        for (int i = 0; i < n; i++)
        {
            k = (arr[i] / d) % 10;
            bucket[k][j[k]] = arr[i]; //������������ ������.
            j[k]++;
        }

        int l = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < j[i]; k++) //��������� ������ ����� ��������
            {
                arr[l] = bucket[i][k];
                l++;
            }
        }
        d *= 10;
    }
}
int main() //����, � ������� �� ������ ������, ��������� bucketsort � ������� ��������������� ������.
{
    setlocale(LC_ALL, "RUS");
    int size;
    int* bucket[10];
    cout << "������� ������ �������." << endl;
    cin >> size;
    int* arr = new int[size + 1];
    for (int i = 0; i < 10; i++)
        bucket[i] = new int[size];
    cout << "������� ������� �������." << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    bucketsort(arr, bucket, size);
    cout << "��������������� ������:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}