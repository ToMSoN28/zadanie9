#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    if (mat->r != b->r) return 2;
    if (mat->r != mat->c) return 2;

    int n     = mat->r;
    Matrix *A = createMatrix(n, n + 1);
    for (int row = 0; row < n; row++) /* łączenie macierzy mat i b w jedną macierz*/
    {
        for (int col = 0; col < n; col++) { A->data[row][col] = mat->data[row][col]; }
        A->data[row][n] = b->data[row][0];
    }
    /*for (int i = 0; i < A->r; i++) {
        if (A->data[i][i] == 0.0) return 1;
    }*/

    // obliczenie elementu z jedna niewiadoma
    x->data[n-1][0] = A->data[n][n + 1] / A->data[n][n];
    double sum    = 0.0;
    for (int row = n - 1; row >= 1; row--) {
        sum = 0.0;
        for (int col = row + 1; col <= n; col++) {
            sum = sum + A->data[row][col] * x->data[col][0];
        }
        x->data[row][0] = (A->data[row][n + 1] - sum) / A->data[row][row];
    }

    for (int row = 0; row < n; row++) /* rozdzielenie macierzy mat i b w jedną macierz */
    {
        for (int col = 0; col < n; col++) { mat->data[row][col] = A->data[row][col]; }
        b->data[row][0] = A->data[row][n];
    }
    return 0;
}
