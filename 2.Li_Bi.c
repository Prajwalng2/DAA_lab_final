#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    clock_t start, end;

    // Linear search
    start = clock();
    int linearIndex = linearSearch(arr, size, key);
    end = clock();
    double linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Binary search
    start = clock();
    int binaryIndex = binarySearch(arr, size, key);
    end = clock();
    double binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (linearIndex != -1) {
        printf("Linear Search: Element found at index %d\n", linearIndex);
    } else {
        printf("Linear Search: Element not found\n");
    }

    if (binaryIndex != -1) {
        printf("Binary Search: Element found at index %d\n", binaryIndex);
    } else {
        printf("Binary Search: Element not found\n");
    }

    printf("Time taken for Linear Search: %f seconds\n", linearTime);
    printf("Time taken for Binary Search: %f seconds\n", binaryTime);

    return 0;
}
