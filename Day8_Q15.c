#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b)
{
    // Base case
    if (b == 0)
        return 1;

    // Recursive call
    return a * power(a, b - 1);
}

int main()
{
    int a, b;

    // Read input
    scanf("%d %d", &a, &b);

    // Print result
    printf("%d", power(a, b));

    return 0;
}
