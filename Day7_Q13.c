#include <stdio.h>

// Function to find Fibonacci number using recursion
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive call
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    // Read input
    scanf("%d", &n);

    // Print nth Fibonacci number
    printf("%d", fib(n));

    return 0;
}
