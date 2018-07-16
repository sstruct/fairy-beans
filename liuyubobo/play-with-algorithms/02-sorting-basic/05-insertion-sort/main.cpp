#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

// 插入排序 -> 整理扑克牌，把小的牌插到前面合适的位置
// 时间复杂度 O(n^2)

template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // 寻找元素 arr[i] 合适的插入位置
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
        }
        // for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        // {
        //     swap(arr[j], arr[j - 1]);
        // }
    }
}

int main()
{
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
    delete[] arr;
    delete[] arr2;

    return 0;
}
