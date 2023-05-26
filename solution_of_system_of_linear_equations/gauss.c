#include <stdio.h>

int main()
{
    // Size of matrix (number of equations)
    int n;

    // Read size of matrix
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    // Augmented matrix (coefficients of variables and constants)
    float A[n][n+1];

    // Read augmented matrix
    printf("Enter the elements of the augmented matrix row-wise:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }

    // Transform augmented matrix to diagonal matrix by row operations
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            // If element is not on the diagonal, subtract a multiple of the element at (j, j)
            if (i != j)
            {
                float c = A[i][j] / A[j][j];
                for (int k = 0; k < n+1; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }

    // Make all diagonal elements 1
    for (int i = 0; i < n; i++)
    {
        A[i][n] = A[i][n] / A[i][i];
        A[i][i] = 1;
    }

    // Print solution
    printf("\nThe solution is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i+1, A[i][n]);
    }

    return 0;
}