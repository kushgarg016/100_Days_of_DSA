#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[10000];
    int size;
} MedianFinder;

// Create object
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->size = 0;
    return obj;
}

// Compare function for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Add number
void medianFinderAddNum(MedianFinder* obj, int num) {
    obj->arr[obj->size++] = num;

    // Sort after insertion
    qsort(obj->arr, obj->size, sizeof(int), cmp);
}

// Find median
double medianFinderFindMedian(MedianFinder* obj) {
    int n = obj->size;

    if (n % 2 == 1) {
        return obj->arr[n / 2];
    } else {
        return (obj->arr[n / 2 - 1] + obj->arr[n / 2]) / 2.0;
    }
}

// Free memory
void medianFinderFree(MedianFinder* obj) {
    free(obj);
}