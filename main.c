#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "headerfile1.h"
//#include "headerfile2.h"
//#include "headerfile3.h"
//#include "headerfile5.h"
//#include "headerfile7.h"
#define debug 1

// 661. Image Smoother
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
	*returnSize = MRowSize;
	int **resultarray = (int **)malloc(sizeof(int*) * MRowSize);
	*columnSizes = calloc(MRowSize, sizeof(int));
	for (int i = 0; i < MRowSize - 1; i++) {
		resultarray[i] = (int *)malloc(sizeof(int)* MColSize);
		(*columnSizes)[i] = MColSize;
	}
	resultarray[0][0] = floor((M[0][1]+M[1][1]+M[1][0])/3);
	resultarray[MRowSize - 1][0] = floor((M[MRowSize - 2][0] + M[MRowSize - 2][1] + M[MRowSize - 1][1]) / 3);
	resultarray[0][MColSize - 1] = floor((M[0][MColSize - 2] + M[1][MColSize - 2] + M[1][MColSize - 1]) / 3);
	resultarray[MRowSize - 1][MColSize - 1] = floor((M[MRowSize - 1][MColSize - 2] + M[MRowSize - 2][MRowSize - 2] + M[MRowSize - 2][MColSize - 1]));
	for (int i = 1; i < MColSize - 2; i++) {
		resultarray[0][i] = floor((M[0][i - 1] + M[0][i + 1] + M[1][i - 1] + M[1][i] + M[1][i + 1]) / 5);
		resultarray[MRowSize-1][i] = floor((M[MRowSize - 1][i - 1] + M[MRowSize - 1][i + 1] + M[MRowSize - 2][i - 1] + M[MRowSize - 2][i] + M[MRowSize - 2][i + 1]) / 5);
	}
	for (int i = 1; i < MRowSize - 2; i++) {
		resultarray[i][0] = floor((M[i - 1][0] + M[i - 1][1] + M[i][1] + M[i + 1][0] + M[i + 1][1]));
		resultarray[i][MColSize-1] = floor((M[i - 1][MColSize - 1] + M[i - 1][MColSize - 2] + M[i][MColSize - 2] + M[i + 1][MColSize - 1] + M[i + 1][MColSize - 2]));
	}
	for (int i = 1; i < MRowSize-1; i++)
		for (int j = 1; j < MColSize-1; j++)
			resultarray[i][j] = floor((M[i - 1][j - 1] + M[i - 1][j] + M[i - 1][j + 1] + M[i][j - 1] + M[i][j + 1] + M[i + 1][j - 1] + M[i + 1][j] + M[i + 1][j + 1]) / 8);

	return resultarray;
}

int main()
{
	int num = 0;
	int b = 0;
	for (; num < 6; num++) {
		int * a = getRow(num, &b);
#if debug
		for (int i = 0; i < b; i++)
			printf("%d ", a[i]);
		printf("\n");
#endif
		free(a);
	}
	return 0;
}