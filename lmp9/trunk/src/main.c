#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);


	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	

	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	
	// if(res == 1){
	// 	 printf("nie poprawna matryca");
	// 	 return 1;
	// }
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);

		printToScreen(x);
		freeMatrix(x);
		printToScreen(A);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}



	freeMatrix(A);
	freeMatrix(b);

    fprintf(stderr, "\n--- Uruchamiam testy jednostkowe backsubst ---\n");

	// Test 1: Poprawna macierz trójkątna 2x2
    Matrix *T = createMatrix(2, 2);
    Matrix *Tb = createMatrix(2, 1);
    Matrix *Tx = createMatrix(2, 1);

    if (T != NULL && Tb != NULL && Tx != NULL) {
        T->data[0][0] = 2.0; T->data[0][1] = 1.0;
        T->data[1][0] = 0.0; T->data[1][1] = 1.0;

        Tb->data[0][0] = 4.0;
        Tb->data[1][0] = 2.0;

        int test_res = backsubst(Tx, T, Tb);

        if (test_res != 0) {
            fprintf(stderr, "[BLAD] Test 1 nie powiodl sie: funkcja zwrocila kod bledu %d\n", test_res);
        } else {
            if (Tx->data[0][0] == 1.0 && Tx->data[1][0] == 2.0) {
                fprintf(stderr, "[OK] Test 1 (Obliczenia): Wynik poprawny [1.0, 2.0]\n");
            } else {
                fprintf(stderr, "[BLAD] Test 1 (Obliczenia): Oczekiwano [1.0, 2.0], otrzymano [%f, %f]\n", 
                        Tx->data[0][0], Tx->data[1][0]);
            }
        }
        freeMatrix(T); freeMatrix(Tb); freeMatrix(Tx);
    }

    // Test 2: Dzielenie przez zero (element na diagonali = 0)
    T = createMatrix(2, 2);
    Tb = createMatrix(2, 1);
    Tx = createMatrix(2, 1);
    
    if (T != NULL && Tb != NULL && Tx != NULL) {
        T->data[0][0] = 2.0; T->data[0][1] = 1.0;
        T->data[1][0] = 0.0; T->data[1][1] = 0.0;

        int err_code = backsubst(Tx, T, Tb);
        if (err_code == 1) {
            fprintf(stderr, "[OK] Test 2 (Dzielenie przez 0): Poprawnie wykryto blad (kod 1)\n");
        } else {
            fprintf(stderr, "[BLAD] Test 2: Oczekiwano kodu 1, otrzymano %d\n", err_code);
        }

        freeMatrix(T); freeMatrix(Tb); freeMatrix(Tx);
    }
    fprintf(stderr, "------------------------------------------\n");


	printf("--------------Test Cases Gauss--------------\n");
	Matrix * C = readFromFile (argv[3]);
	Matrix *bC = readFromFile(argv[2]);
	Matrix * y;


	if(C == NULL) return -3;

	printf("test dla matrycy o nie kwadratowych wymiarach\n ");
	printToScreen(C);

	res = eliminate(C,bC);
	if(res == 1){
		printf("podana macierz jest albo osobliwa albo ma niepoprawne wymiary\n");
		
	}else{

		y = createMatrix(bC->r,1);
		if(y != NULL){
			res = backsubst(y,C,bC);

			printToScreen(y);
			freeMatrix(y);
			printToScreen(C);
		}else{
			fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");

		}

		freeMatrix(C);
		freeMatrix(bC);
	}
	// test dla matrycy osobliwej

	Matrix *D = readFromFile(argv[4]);
	Matrix *bD = readFromFile(argv[2]);
	Matrix *z;

	if(D == NULL) return -4;

	printf("test dla matrycy której wiersz jest zapełniony zerami\n");
	printToScreen(D);
	
	z = createMatrix(bD->r ,1);
	res = eliminate(C, bD);
	if(res == 1){
		printf("podana macierz jest albo osobliwa albo ma niepoprawne wymiary\n");
		
	}else{

		y = createMatrix(bD->r,1);
		if(z!= NULL){
			res = backsubst(y,D,bD);
			printToScreen(z);
			freeMatrix(z);
			printToScreen(D);
		}else{
			fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
		}
		freeMatrix(D);
		freeMatrix(bD);
	}
	return 0;
}
