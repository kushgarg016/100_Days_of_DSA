#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int j = 0;

    // Move non-zero elements forward
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    // Fill remaining positions with zeros
    while (j < numsSize) {
        nums[j++] = 0;
    }
}

// Test driver
int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
