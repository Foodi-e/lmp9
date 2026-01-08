#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int double_rowne(double a, double b) {
    return fabs(a - b) < 0.000001;
}

void testy() {
    printf("--- Uruchamianie testów jednostkowych ---\n");

    Matrix *A = createMatrix(2, 2);
    Matrix *b = createMatrix(2, 1);
    Matrix *x = createMatrix(2, 1);

    A->data[0][0] = 2.0; A->data[0][1] = 1.0;
    A->data[1][0] = 4.0; A->data[1][1] = 4.0;
    b->data[0][0] = 5.0; b->data[1][0] = 12.0;

    int res_g = eliminate(A, b);
    int res_b = backsubst(x, A, b);

    printf("Test 1 (Układ równań 2x2): ");
    if (res_g == 0 && res_b == 0 && double_rowne(x->data[0][0], 2.0) && double_rowne(x->data[1][0], 1.0)) {
        printf("SUKCES\n");
    } else {
        printf("BŁĄD (Oczekiwano x=2, y=1)\n");
    }

    A->data[0][0] = 0.0; A->data[0][1] = 1.0;
    A->data[1][0] = 0.0; A->data[1][1] = 2.0;
    
    printf("Test 2 (Macierz osobliwa): ");
    if (eliminate(A, b) == 1) {
        printf("SUKCES (Wykryto zero na przekątnej)\n");
    } else {
        printf("BŁĄD (Nie wykryto macierzy osobliwej)\n");
    }

    freeMatrix(A);
    freeMatrix(b);
    freeMatrix(x);
    printf("--- Testy zakończone ---\n\n");
}

int main(int argc, char ** argv) {
	///1980273091hdwufos
	
	if (argc < 3) {
        testy();
        printf("Użycie: %s [macierz] [wektor]\n", argv[0]);
        return 0;
    }
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	

	res = eliminate(A,b);
	if (res != 0) {
        fprintf(stderr, "Błąd! Macierz osobliwa lub błędne dane.\n");
        freeMatrix(A);
        freeMatrix(b);
        return -3;
    }

	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if (res == 0) {
			printToScreen(x);
		} else {
            fprintf(stderr, "Błąd wstecznego podstawienia! Kod: %d\n", res);
        }
	    freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
