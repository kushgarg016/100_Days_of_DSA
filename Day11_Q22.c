#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize,
               int* returnSize, int** returnColumnSizes) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    *returnSize = cols;

    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
    }

    int** result = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int main() {

    int r = 2, c = 3;

    int data[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int** matrix = malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            matrix[i][j] = data[i][j];
        }
    }

    int matrixColSize[1] = {c};
    int returnSize;
    int* returnColumnSizes;

    int** result = transpose(matrix, r, matrixColSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
