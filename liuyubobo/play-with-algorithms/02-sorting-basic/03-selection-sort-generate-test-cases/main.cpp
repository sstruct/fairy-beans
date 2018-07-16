#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"

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
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    selectionSort(arr, n);
    SortTestHelper::printArray(arr, n);
    delete[] arr;

    return 0;
}
