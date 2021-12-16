#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int n     = mat->r;
    Matrix *A = createMatrix(n + 1, n);
    for (int row = 0; row <= n; row++) /* łączenie macierzy mat i b w jedną macierz*/
    {
        for (int col = 0; col <= n; col++) { A->data[row][col] = mat->data[row][col]; }
        A->data[row][n + 1] = b->data[row][0];
    }

    for (int col = 1; col <= n; col++) { /* eliminacja*/
        for (int row = 1; row <= n; row++) {
            if (row > col) {
                double c = A->data[row][col] * A->data[col][col];
                for (int k = 1; k <= n + 1; k++) {
                    if (A->data[col][k] == 0.0) return 1;
                    A->data[row][k] = A->data[row][k] - c / A->data[col][k];
                }
            }
        }
    }

    for (int row = 0; row <= n; row++) /* rozdzielenie macierzy mat i b w jedną macierz*/
    {
        for (int col = 0; col <= n; col++) { mat->data[row][col] = A->data[row][col]; }
        b->data[row][0] = A->data[row][n + 1];
    }
    return 0;
}
