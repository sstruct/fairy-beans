#include <iostream>
#include <algorithm>
#include "Student.h"

using namespace std;

// 选择排序
// 时间复杂度 O(n^2)

template <typename T>
void selectionSort(T arr[], int n)
{
    // 寻找[i, n)区间里的最小值
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    float b[3] = {3.3, 2.2, 1.1};
    int n1 = 3;
    selectionSort(b, n1);
    for (int i = 0; i < n1; i++)
        cout << b[i] << " ";
    cout << endl;

    string c[3] = {"D", "C", "B"};
    selectionSort(c, n1);
    for (int i = 0; i < n1; i++)
        cout << c[i] << " ";
    cout << endl;

    Student d[3] = {{"D", 90}, {"C", 80}, {"B", 80}};
    selectionSort(d, n1);
    for (int i = 0; i < n1; i++)
        cout << d[i];
    cout << endl;

    return 0;
}
