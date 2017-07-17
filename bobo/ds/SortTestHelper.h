// 避免多重宏定义的问题
#ifndef FAIRY_BEANS_SORTTESTHELPER_H
#define FAIRY_BEANS_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortTestHelper {

    // 生成有 n 个元素的随机数组，每个元素的随机范围为 [rangeL, rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);
        int *arr = new int[n];
        // 设置随机种子，将当前时间作为随机种子
        srand(time(NULL));

        for (int i = 0; i < n; i++)
            /**
             * 生成随机数组，rand() 返回一个随机整数
             * 这里 rangeR - rangeL 为什么还要加 1 呢❓
             * 反过来，当取值正好为 rangeR 时，如 10 - 5 = 5
             * rand() % (rangeR - rangeL (+ 1)) == 5 => rangeR- rangeL (+ 1) != 5
             * 对于 [5, 10]，rangeR - rangeL = 5，需要进行偏移，那么为什么要偏移到 6 呢？
             * 用 Grapher 绘图 y1 = x % 5 + 5 vs y2 = x % 6 + 5
             * 可以观察到，y1 的图像范围是 y2 的子集，y1 缺少最大取值
             * let rangeR = 10, rangeL = 5, rand() = 10
             * rand() % (rangeR - rangeL) + rangeL = 10 % 5 + 5 = 0 + 5= 5
             * rand() % (rangeR - rangeL + 1) + rangeL = 10 % 6 + 5= 4 + 5 = 9
             */
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    // COPY 整型数组
    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++)
            // 打印文字（cout -> c output，endl -> end of line）
            cout << arr[i] << ' ';
        cout << endl;
    }

    // 测试排序是否成功
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    // 输出测试时间
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        // CLOCKS_PER_SEC 每秒钟时钟周期数
        cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        return;
    }
}

#endif //FAIRY_BEANS_SORTTESTHELPER_H
