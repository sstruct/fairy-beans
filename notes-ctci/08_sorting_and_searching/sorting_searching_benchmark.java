class SortingSearchingBenchmark {
  public static void main(String[] args) {
    QuickSort.init();
    MergeSort.init();
    BinarySearch.init();

    // int size = 10;
    int size = 5_000_000;
    System.out.println("Sorting test data size: " + size);

    int[] testValue = Utils.generateTestValue(size);
    // 保证相同测试集
    int[] testValue2 = new int[size];
    System.arraycopy(testValue, 0, testValue2, 0, size);

    long startTime = System.nanoTime();
    // Do the job here
    QuickSort.sort(testValue, 0, size - 1);
    long endTime = System.nanoTime();
    // Duration in seconds
    double duration = (double) (endTime - startTime) / 1_000_000_000;
    System.out.print("QuickSort(" + Utils.isSortedArray(testValue) + "): " + duration + "s\n");

    startTime = System.nanoTime();
    MergeSort.sort(testValue2);
    endTime = System.nanoTime();
    duration = (double) (endTime - startTime) / 1_000_000_000;
    System.out.print("MergeSort(" + Utils.isSortedArray(testValue2) + "): " + duration + "s\n");

    /** ============ searching ============= */

    int searchSize = 600_000_000;
    System.out.println("Searching test data size: " + searchSize);

    int[] searchTestData = new int[searchSize];
    for (int i = 0; i < searchSize; i++) {
      searchTestData[i] = i;
    }
    int x = (int) (Math.random() * searchSize);

    startTime = System.nanoTime();
    BinarySearch.search_iter(searchTestData, x);
    endTime = System.nanoTime();
    duration = (double) (endTime - startTime) / 1_000_000;
    System.out.print("BinarySearch(iterative): " + duration + "ms\n");

    startTime = System.nanoTime();
    BinarySearch.search_recur(searchTestData, x, 0, searchSize - 1);
    endTime = System.nanoTime();
    duration = (double) (endTime - startTime) / 1_000_000;
    System.out.print("BinarySearch(recursive): " + duration + "ms\n");
  }
}