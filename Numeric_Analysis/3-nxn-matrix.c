#include<stdio.h>
#include<math.h>

#define MAX_SIZE 5

float determinant(float matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int c;
    float det=0, s=1;
    float b[MAX_SIZE][MAX_SIZE];
    int i, j;
    int m, n;

    if(size == 1)
    {
        return matrix[0][0];
    }
    else
    {
        det = 0;
        for(c = 0; c < size; c++)
        {
            m = 0;
            n = 0;
            for(i = 0; i < size; i++)
            {
                for(j = 0; j < size; j++)
                {
                    b[i][j] = 0;
                    if(i != 0 && j != c)
                    {
                        b[m][n] = matrix[i][j];
                        if(n < (size - 2))
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
            det = det + s * (matrix[0][c] * determinant(b, size - 1));
            s = -1 * s;
        }
    }
    return det;
}

int main()
{
    int n;
    printf("Enter the size n*n of the matrix: ");
    scanf("%d", &n);

    if(n != MAX_SIZE)
    {
        printf("Please enter a 5x5 matrix.\n");
        return 1;
    }

    float matrix[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("Enter the [%d][%d] element of the matrix: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    float result = determinant(matrix, n);
    printf("The determinant of the matrix is %f\n", result);

    return 0;
}
