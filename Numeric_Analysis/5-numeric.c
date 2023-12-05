#include <stdio.h>
#include <math.h>

float det(float matrix[25][25], int size)
{

    int c;
    float det = 0, s = 1;
    float b[25][25];
    int i, j;
    int m, n;
    if (size == 1)
    {
        return (matrix[0][0]);
    }
    else
    {
        det = 0;
        for (c = 0; c < size; c++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {
                    b[i][j] = 0;
                    if (i != 0 && j != c)
                    {
                        b[m][n] = matrix[i][j];
                        if (n < (size - 2))
                        {
                            n++;
                        }
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det = det + s * (matrix[0][c] * det(b, size - 1));
            s = -1 * s;
        }
    }
    return (det);
}
int main()
{
    int n;
    printf("Enter the size n*n of the matrix ");
    scanf("%d", &n);
    int i, j;
    float matrix[25][25];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the %d%d element of the matrix ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }
    float result = det(matrix, n);
    printf("The determinent of the matrix is %f", result);
}