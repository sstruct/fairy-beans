// Runtime: O(n log(n)) average, O(n^2) worst case. Memory: O(log(n)).

class QuickSort {
    public static void init() {
    }

    public static void sort(int[] arr, int left, int right) {
        int index = partition(arr, left, right);
        // Sort left half
        if (left < index - 1)
            sort(arr, left, index - 1);
        // Sort right half
        if (index < right)
            sort(arr, index, right);
    }

    public static int partition(int[] arr, int left, int right) {
        int pivot = arr[(left + right) / 2];
        while (left <= right) {
            while (arr[left] < pivot)
                left++;
            while (arr[right] > pivot)
                right--;
            if (left <= right) {
                Utils.swap(arr, left++, right--);
            }
        }
        return left;
    }
}
