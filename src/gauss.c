#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int n     = mat->r;
    Matrix *A = createMatrix(n, n + 1);
    for (int row = 0; row < n; row++) /* łączenie macierzy mat i b w jedną macierz*/
    {
        for (int col = 0; col < n; col++) { A->data[row][col] = mat->data[row][col]; }
        A->data[row][n] = b->data[row][0];
    }

    for (int col = 0; col < n; col++) { /* eliminacja*/
        for (int row = 0; row < n; row++) {
            if (row > col) {
                if (A->data[col][col] == 0.0) return 1;
                double c = A->data[row][col] / A->data[col][col];
                for (int k = 0; k < n + 1; k++) {
                    A->data[row][k] = A->data[row][k] - c * A->data[col][k];
                }
            }
        }
    }

    for (int row = 0; row < n; row++) /* rozdzielenie macierzy mat i b w jedną macierz*/
    {
        for (int col = 0; col < n; col++) { mat->data[row][col] = A->data[row][col]; }
        b->data[row][0] = A->data[row][n];
    }
    return 0;
}
