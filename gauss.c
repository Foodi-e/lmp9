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


int eliminate(Matrix *matryca, Matrix *wyniki){
	int liczbaR = matryca->r;
	int liczbaC = matryca->c;
	
	
	if(liczbaC!=liczbaR||wyniki->r != liczbaR||wyniki->c != 1) return 1;
	
	

	int i ,j,k;
	double ratio;
	for(i=0;i<liczbaC;i++){
		
		if(fabs(matryca->data[i][i])<0.0001) return 1;
		
		for(j=i;j<liczbaR;j++){
			if(j>i){
				ratio = matryca->data[j][i]/matryca->data[i][i];
				for(k=0;k<liczbaC;k++){
					matryca->data[j][k] = matryca->data[j][k]-ratio *matryca->data[i][k];
					
				}
				wyniki->data[j][0] = wyniki->data[j][0]-ratio*wyniki->data[i][0];
				
			}
		}
	}
	
	return 0;	
}	

