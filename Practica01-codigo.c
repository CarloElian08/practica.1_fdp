#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void get_walltime(double * wcTime) {
struct timeval tp;
mingw_gettimeofday(&tp, NULL);
*wcTime = (tp.tv_sec + tp.tv_usec /1000000.0);

}

int main(int argc, char* argv[]) {
	int i, j,k, n = 10000;
	int ** matrizA,**matrizB,**matrizC;
	double S1,E1,E2,auxiliar;
	// I n i c i a l i z a n d o m a t ri c e s
	matrizA = (int **)malloc(n* sizeof(int *));
	matrizB=(int **)malloc(n* sizeof(int *));
	matrizC=(int **)malloc(n* sizeof(int *));
	for (i = 0; i < n; i++){
		*(matrizA + i) = (int *)malloc(n* sizeof(int));
		*(matrizB + i) = (int *)malloc(n* sizeof(int));
		*(matrizC + i) = (int *)malloc(n* sizeof(int));
	}
	//Llenando m a t ri c e s
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			matrizA[i][j] = rand() % 6;
			matrizB[i][j]=rand()%6;
		}
	}
	get_walltime(&S1);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j< n; ++j)
		{
			for (k = 0;k < n; ++k)
			{
				matrizC[i][j] += matrizA[i][k] *matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);
	auxiliar=E1-S1;
    printf("Tiempo medido para la combinacion i, j, k: %lf [s]\n",auxiliar);
    for (i = 0; i < n; i++){
		free(*(matrizA + i));
		free(*(matrizB + i));
		free(*(matrizC + i));
	}
    free(matrizA);
    free(matrizB);
    free(matrizC);
	return 0;
}
