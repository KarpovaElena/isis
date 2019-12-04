#include <stdio.h>
#include <stdlib.h>
#include <showpnm.h>

int showpnm(int x, int y, int c) {
	/*
		x - columns
		y - rows
	*/
	int **img = malloc(sizeof(int *) * y);
	for (int i = 0; i < y; i++) 
	{
		img[i] = malloc(sizeof(int) * x);
	}	
	
	for (int i = 0; i < y; i++) 
	{
		for (int j = 0; j < x; j++)
		{
			img[i][j] = c;
			printf("%d ", img[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < y; i++) 
		free(img[i]);
	free(img);
}

