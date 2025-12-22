#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if(mat->c != mat->r) return 2;
	if(mat->r != x->r) return 2;
	if(mat->r != b->r) return 2;
	if(x->c != 1) return 2;
	if(b->c != 1) return 2;

	for (int i = mat->r - 1; i >= 0; i--) {
        double s = 0;

        if (mat->data[i][i] == 0) {
            return 1;
        }

        for (int j = i + 1; j < mat->r; j++) {
            s += mat->data[i][j] * x->data[j][0];
        }

        x->data[i][0] = (b->data[i][0] - s) / mat->data[i][i];
    }

	return 0;
}


