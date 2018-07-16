#include <iostream>
#include <algorithm>

using namespace std;

// 选择排序
// 时间复杂度 O(n^2)

void selectionSort(int arr[], int n)
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
    return 0;
}
