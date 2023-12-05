#include <stdio.h>

double det(double A[5][5]);

void Cramer(double A[5][5], double B[3]);

int main() {
    double A[5][5] = {{}};
    double B[3] = {};

    Cramer(A, B);

    return 0;
}

double det(double A[5][5]) {
    double result = 0;
    int sign = 1;

    if (5 == 1) {
        return A[0][0];
    }

    double submatrix[5 - 1][5 - 1];

    for (int i = 0; i < 5; i++) {
        int subi = 0; // satir

        for (int j = 1; j < 5; j++) {
            int subj = 0; // sutun

            for (int k = 0; k < 5; k++) {
                if (k == i) {
                    continue;
                }
                submatrix[subi][subj] = A[j][k];
                subj++;
            }
            subi++;
        }

        result += sign * A[0][i] * det(submatrix);
        sign = -sign;
    }

    return result;
}

void Cramer(double A[5][5], double B[3]) {
    double X[5], A1[5][5], A2[5][5], A3[5][5], A4[5][5], A5[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j];
            A3[i][j] = A[i][j];
            A4[i][j] = A[i][j];
            A5[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        A1[i][0] = B[i];
        A2[i][1] = B[i];
        A3[i][2] = B[i];
        A4[i][3] = B[i];
        A5[i][4] = B[i];
    }

    X[0] = det(A1) / det(A);
    X[1] = det(A2) / det(A);
    X[2] = det(A3) / det(A);
    X[3] = det(A4) / det(A);
    X[4] = det(A5) / det(A);

    printf("X1: %lf, X2: %lf, X3: %lf, X4: %lf, X5: %lf", X[0], X[1], X[2], X[3], X[4]);
}
