#include "gauss.h"
#include "gauss.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	Matrix *b = malloc(sizeof(Matrix));
	b->c = 3;
	b->r = 3;
	double **matryca = malloc(sizeof(double*)*b->r);for(int i=0;i<b->r;i++)matryca[i] = malloc(sizeof(double)*b->c);
	for(int i=0;i<b->c;i++){ 		// losowe wartość dla macierzy
		for(int j=0;j<b->r;j++){
			matryca[i][j] = (double)(rand()%10)+1;
		}
	}
	
	b->data = matryca;

	int i,j;
	for(i=0;i<b->c;i++){ 			// printowanie przed eliminacją
		for(j=0;j<b->r;j++){
			printf("%.2f ",b->data[i][j]);
		}
		printf("\n");
	}

    

    printf("\n\n");
	Matrix *mat = malloc(sizeof(Matrix));
	mat->c = 1;
	mat->r = 3; // wielkość macierzy 

	double **matZWynikami = malloc(sizeof(double*)*mat->c); for(int i=0;i<mat->r;i++) matZWynikami[i] = malloc(sizeof(double)); 

	matZWynikami[0][0] = rand()%10+1;			// jakieś losowe liczby dla prawej
	matZWynikami[1][0] = rand()%10+1;
	matZWynikami[2][0] = rand()%10+1;
	mat->data = matZWynikami;
    printf(" to jest macierz prawa :\n%.2f\n,%.2f\n,%.2f\n",mat->data[0][0],mat->data[1][0],mat->data[2][0]);
    printf("to jest macierz po prekształceniu gaussa\n");
	eliminate(mat,b);
	for(i=0;i<b->c;i++){ // printowanie po eliminacji
		for(j=0;j<b->r;j++){
			printf("%.2f ",b->data[i][j]);
		}
		printf("\n");
	}

	printf(" to jest macierz prawa :\n%.2f\n,%.2f\n,%.2f\n",mat->data[0][0],mat->data[1][0],mat->data[2][0]);

	for(int i=0;i<3;i++){
		free(matZWynikami[i]);
		free(matryca[i]);
	}
	free(matryca);
	free(matZWynikami);

	return 0;
}