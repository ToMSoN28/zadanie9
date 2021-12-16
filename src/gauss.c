#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int n = mat->r;
    Matrix* A = createMatrix(n + 1, n);
    for (int row = 0; row <= n; row++) /* łączenie macierzy mat i b w jedną macierz*/
    {
        for (int col = 0; col <= n; col++) {
            A[row][col] = mat[row][col];
        }
        A[row][n + 1] = b[row][0];
    }

    for (int col = 1; col <= n; col++) /* eliminacja*/
        for (int row = 1; row <= n; row++) {
            if (row > col) {
                c = A[row][col] * A[col][col];
                for (k = 1; k <= n + 1; k++) { A[row][k] = A[row][k] - c * A[col][k]; }
            }
        }
    }

for (int row = 0; row <= n; row++) /* łrozdzielenie macierzy mat i b w jedną macierz*/
{
    for (int col = 0; col <= n; col++) {
        mat[row][col] = A[row][col];
    }
    b[row][0] = A[row][n+1];
}
		return 0;
}

