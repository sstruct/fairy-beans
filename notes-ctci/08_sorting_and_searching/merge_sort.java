class MergeSort {
  public static void init() {
  }

  public static void sort(int[] array) {
    // System.out.println("merge sorting");
    int[] helper = new int[array.length];
    mergesort(array, helper, 0, array.length - 1);
  }

  public static void mergesort(int[] array, int[] helper, int low, int high) {
    if (low < high) {
      int middle = (low + high) / 2;
      mergesort(array, helper, low, middle);
      mergesort(array, helper, middle + 1, high);
      merge(array, helper, low, middle, high);
    }
  }

  public static void merge(int[] array, int[] helper, int low, int middle, int high) {
    for (int i = low; i <= high; i++) {
      // helper: clone array
      helper[i] = array[i];
    }
    int helperLeft = low;
    int helperRight = middle + 1;
    int current = low;
    // 遍历 helper 数组，比较左右两边，
    while (helperLeft <= middle && helperRight <= high) {
      if (helper[helperLeft] <= helper[helperRight]) {
        array[current] = helper[helperLeft++];
      } else {
        array[current] = helper[helperRight++];
      }
      current++;
    }
    int remaining = middle - helperLeft;
    for (int i = 0; i <= remaining; i++) {
      array[current + i] = helper[helperLeft + i];
    }
  }
};
