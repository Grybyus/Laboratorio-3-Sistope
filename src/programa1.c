#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LARGO (536870912/2)

int programa1(){
	int i;
	float array[20];
	int x,*y;
	y=(int *)malloc( sizeof(int) *LARGO);	

	clock_t start = clock();
	for (i = 0; i < 20; i++)
	{

		for (x = 0; x < LARGO; x++)
		{
			y[x] = rand()%LARGO;

		}
		array[i]=((double)clock() - start) / CLOCKS_PER_SEC;

	}
	free(y);

	float varianza,desviaStandard,media = array[19]/(float)20;
	varianza = (float)0;

	for (i = 19; i > 0 ; i--)
	{
		array[i] = array[i] - array[i-1];
		printf("Han pasado : %f sec, en la iteracion %i\n", array[i],i);
	}
		printf("Han pasado : %f sec, en la iteracion %i\n", array[0],0);
	printf("La media es = %f \n", media);
	
	for (i = 19; i >= 0 ; i--)
	{
		varianza = varianza + powf((array[i] - media),2);
	}
	varianza = varianza/(float)20;
	printf("Varianza : %f -\n",varianza);
	desviaStandard = sqrtf(varianza);
	printf("Desviacion Standard %f -\n",desviaStandard);

	return 0;
}
