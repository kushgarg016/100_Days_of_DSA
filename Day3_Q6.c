#include <stdio.h>

int missingNum(int *arr, int size) {
    long long expectedSum = (long long)(size + 1) * (size + 2) / 2;
    long long actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}

int main() {
  
    int arr[] = {1, 2, 3, 5};

    int size = sizeof(arr) / sizeof(arr[0]);

    int result = missingNum(arr, size);

    printf("Missing number is: %d\n", result);

    return 0;
}
