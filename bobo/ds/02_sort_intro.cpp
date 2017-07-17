/**
 * 排序：选择排序、插入排序
 * O(n^2)
 */
#include <iostream>
// 自定义的文件，用 双引号 引入
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

// 模版（or 范型），对不同数据类型做相似处理
template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[minIndex] > arr[j]) {
                swap(arr[minIndex], arr[j]);
            }
        }
    }
}

template<typename T>
void insertionSort(T arr[], int n) {
    // i = 1 是因为第 0 位已经排好
    for (int i = 1; i < n; i++) {
        T e = arr[i];
        int j;
        // j = 0 时，arr[j - 1] 不存在
        for (j = i; j > 0 && e < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}

int main() {
    // 声明一个数组
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 100, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    // 取同类型元素数组的长度
    SortTestHelper::testSort("selection sort", selectionSort, arr, n);
    SortTestHelper::testSort("insertion sort", insertionSort, arr2, n);
//    SortTestHelper::printArray(arr, n);
    delete[] arr;
    delete[] arr2;

    float farr[] = {1.1, 2.2, 1.0, 1.5};
    int fn = sizeof(farr) / sizeof(farr[0]);
    selectionSort(farr, fn);
    SortTestHelper::printArray(farr, fn);
    cout << endl;

    string sarr[] = {"c", "d", "b", "A", "D", "a"};
    int sn = sizeof(sarr) / sizeof(sarr[0]);
    selectionSort(sarr, sn);
    SortTestHelper::printArray(sarr, sn);

    Student d[] = {{"d", 90},
                   {"a", 80}};
    int sd = sizeof(d) / sizeof(d[0]);
    selectionSort(d, sd);
    for (int i = 0; i < sd; i++)
        cout << d[i];
    cout << endl;

    return 0;
}
