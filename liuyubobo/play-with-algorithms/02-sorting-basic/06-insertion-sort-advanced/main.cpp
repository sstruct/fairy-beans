#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

// 插入排序 -> 整理扑克牌，把小的牌插到前面合适的位置
// 时间复杂度 O(n^2)，最优时间复杂度 O(n) -> 在数据近乎有序的情况下

template <typename T>

void insertionSort(T arr[], int n)
{
    // 从左向右遍历
    // 第 0 个元素不需要遍历，因为它一定是前面所有元素中最小的
    for (int i = 1; i < n; i++)
    {
        // e 保存元素 arr[i]，用于寻找其合适的插入位置
        T e = arr[i];
        // j 保存元素 e 应该插入的位置
        int j;
        // 从第 i 个元素开始向左查找，直至 j = 1
        for (j = i; j > 0; j--)
        {
            // 判断 e 是否应该放在前一个位置，是则将原来的数右移
            if (arr[j - 1] > e)
                arr[j] = arr[j - 1];
            // 当 j = 1 或者找不到更小的数时，j 就是要寻找的位置
            else
                break;
        }
        arr[j] = e;
    }
}

int main()
{
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
    delete[] arr;
    delete[] arr2;

    return 0;
}
