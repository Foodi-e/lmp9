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

	printf("--------------Test Cases--------------\n");
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
