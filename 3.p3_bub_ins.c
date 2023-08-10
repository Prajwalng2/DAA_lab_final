#include <stdio.h>
#include <string.h>
#include <time.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char binary[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (binary[j] == '1' && binary[j + 1] == '0') {
                swap(&binary[j], &binary[j + 1]);
            }
        }
    }
}

void insertionSort(char binary[], int size) {
    for (int i = 1; i < size; i++) {
        char key = binary[i];
        int j = i - 1;
        while (j >= 0 && key == '0' && binary[j] == '1') {
            binary[j + 1] = binary[j];
            j--;
        }
        binary[j + 1] = key;
    }
}

int main() {
    int size;
    printf("Enter the size of the row: ");
    scanf("%d", &size);

    char binary[size + 1]; // +1 for null-terminator
    printf("Enter the row of binary digits: ");
    for (int i = 0; i < size; i++) {
        scanf(" %c", &binary[i]);
    }
    binary[size] = '\0'; // Null-terminate the string

    clock_t start, end;

    // Perform Bubble Sort
    char bubbleArr[size + 1];
    strcpy(bubbleArr, binary);
    start = clock();
    bubbleSort(bubbleArr, size);
    end = clock();
    double bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Perform Insertion Sort
    char insertionArr[size + 1];
    strcpy(insertionArr, binary);
    start = clock();
    insertionSort(insertionArr, size);
    end = clock();
    double insertionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Row after Bubble Sort: %s\n", bubbleArr);
    printf("Time taken for Bubble Sort: %f seconds\n", bubbleTime);

    printf("Row after Insertion Sort: %s\n", insertionArr);
    printf("Time taken for Insertion Sort: %f seconds\n", insertionTime);

    return 0;
}
