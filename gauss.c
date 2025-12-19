#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

// porownanie kolumn i rzedow


int eliminate(Matrix *b, Matrix *mat){
	int liczbaR = b->r;
	int liczbaC = b->c;
	

	if(liczbaC!=liczbaR) return 0;

	int i ,j,k;
	double ratio;
	for(i=0;i<liczbaC;i++){
		for(j=i;j<liczbaR;j++){
			if(j>i){
				ratio = b->data[j][i]/b->data[i][i];
				for(k=0;k<liczbaC;k++){
					b->data[j][k] = b->data[j][k]-ratio *b->data[i][k];
					
				}
				mat->data[j][0] = mat->data[j][0]-ratio*mat->data[i][0];
				
			}
		}
		if(b->data[i][i]==0) return 0;
	}
	
	return 0;	
}	

