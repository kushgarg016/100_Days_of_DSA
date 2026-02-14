#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    int a[n][n];

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check identity matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1) {
                printf("Not an Identity Matrix");
                return 0;
            }
            if(i != j && a[i][j] != 0) {
                printf("Not an Identity Matrix");
                return 0;
            }
        }
    }

    printf("Identity Matrix");
    return 0;
}
