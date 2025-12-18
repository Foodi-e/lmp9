#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int liczbaR = b->r;
	int liczbaC = b->c;
	double **matryca = b->data;
	double **mat_wyn = mat->data;
    // if( obliczanieWyz == 1) return 1;
	int i ,j,k;
	double ratio;
	for(i=0;i<liczbaC;i++){
		for(j=0;j<liczbaR;j++){
			if(j>i){
				ratio = matryca[j][i]/matryca[i][i];
				for(k=0;k<liczbaC;k++){
					matryca[j][k] = matryca[j][k]-ratio *matryca[i][k];
					
				}
				mat_wyn[i][0] = mat_wyn[i][0]-ratio*mat_wyn[i][0];
			}
		}
	}
		
}	

// int det = 0;
// int obliczanieWyz(Matrix *b){
// 	int liczbaR = b->r;
// 	int liczbaC = b->c;
// 	int wyznacznik = 0;
// 	int **matryca = b->data;
// 	int liczba0 = 0;

// 	if(liczbaC!=liczbaR) return 0;// sprawdza czy macierz jest kwadratowa

// 	else{//sprawdza czy wiersz nie składa się z 0
		
		
// 	}
// 	return 1;
// }

