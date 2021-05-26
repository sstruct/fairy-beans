// In Java, class can be accessed anywhere within the same package. That is awesome!

class Utils {
  public static void swap(int[] arr, int left, int right) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
  }

  // TODO: 支持生成生序、降序、等值等测试数据
  public static int[] generateTestValue(int size) {
    int[] numbers = new int[size];
    for (int i = 0; i < size; i++) {
      numbers[i] = (int) (Math.random() * size * 10 + 1);
    }
    return numbers;
  }

  // TODO: 自动测会比较好
  public static void timer() {
    long startTime = System.nanoTime();
    // Do the job here
    // ...
    long endTime = System.nanoTime();
    // Duration in seconds
    double duration = (double) (endTime - startTime) / 1_000_000_000;
    System.out.print(duration);
  }

  // TODO: 降序？
  public static boolean isSortedArray(int[] arr) {
    for (int i = 0; i < arr.length - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        return false;
      }
    }
    return true;
  }
}
