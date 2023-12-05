#include <stdio.h>

#define N 5

double determinant(double mat[N][N], int n);

int main() {
    double mat[N][N];

    // Input matrix elements from the user
    printf("Enter the elements of the 5x5 matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%lf", &mat[i][j]);
        }
    }

    double det = determinant(mat, N);

    printf("Determinant: %lf\n", det);

    return 0;
}

double determinant(double mat[N][N], int n) {
    double det = 0;

    if (n == 1) {
        return mat[0][0];
    }

    double submatrix[N - 1][N - 1];

    for (int k = 0; k < n; k++) {
        int subi = 0; // submatrix row index

        for (int i = 1; i < n; i++) {
            int subj = 0; // submatrix column index

            for (int j = 0; j < n; j++) {
                if (j == k) {
                    continue;
                }
                submatrix[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }

        det += (k % 2 == 0 ? 1 : -1) * mat[0][k] * determinant(submatrix, n - 1);
    }

    return det;
}
