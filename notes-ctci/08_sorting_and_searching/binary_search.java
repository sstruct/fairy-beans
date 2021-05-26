// Search index of x in a sorted array

class BinarySearch {
  public static void init() {
  }

  // Time O(n^2), Space O(1)
  public static int search_iter(int[] arr, int x) {
    int low = 0;
    int high = arr.length - 1;
    int mid;
    while (low <= high) {
      mid = (low + high) / 2;
      if (arr[mid] == x)
        return mid;
      if (arr[mid] < x)
        low = mid + 1;
      if (arr[mid] > x)
        high = mid - 1;
    }
    return -1;
  }

  // Time O(n^2), Space O(log n)
  public static int search_recur(int[] arr, int x, int low, int high) {
    if (low > high)
      return -1;
    int mid = (low + high) / 2;
    if (arr[mid] > x)
      return search_recur(arr, x, low, mid - 1);
    if (arr[mid] < x)
      return search_recur(arr, x, mid + 1, high);
    return mid;
  }
}

// Thoughts: hash table
