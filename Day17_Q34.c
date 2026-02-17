#include <stdio.h>

int maxSubArray(int arr[], int n)
{
    int currentSum = arr[0];
    int maxSum = arr[0];

    for(int i = 1; i < n; i++)
    {
        // If current sum becomes negative, start new subarray
        if(currentSum < 0)
            currentSum = arr[i];
        else
            currentSum = currentSum + arr[i];

        // Update maximum sum
        if(currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = maxSubArray(arr, n);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}
