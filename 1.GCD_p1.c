#include <stdio.h>
#include <time.h>

int middleSchoolGCD(int a, int b) {
    int smaller = (a < b) ? a : b;
    int gcd = 1;

    for (int i = 2; i <= smaller; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int euclidsDivisionGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int euclidsSubtractionGCD(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    return a;
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    clock_t start, end;

    // Middle school procedure
    start = clock();
    int middleSchoolResult = middleSchoolGCD(num1, num2);
    end = clock();
    double middleSchoolTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Euclid's algorithm by division
    start = clock();
    int divisionResult = euclidsDivisionGCD(num1, num2);
    end = clock();
    double divisionTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Euclid's algorithm by subtraction
    start = clock();
    int subtractionResult = euclidsSubtractionGCD(num1, num2);
    end = clock();
    double subtractionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Middle School GCD: %d\n", middleSchoolResult);
    printf("Euclid's Division GCD: %d\n", divisionResult);
    printf("Euclid's Subtraction GCD: %d\n", subtractionResult);

    printf("Time taken for Middle School GCD: %f seconds\n", middleSchoolTime);
    printf("Time taken for Euclid's Division GCD: %f seconds\n", divisionTime);
    printf("Time taken for Euclid's Subtraction GCD: %f seconds\n", subtractionTime);

    return 0;
}


