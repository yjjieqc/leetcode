#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

// 378. Kth Smallest Element in a Sorted Matrix
int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
	int small = matrix[0][0], big = matrix[matrixRowSize - 1][matrixRowSize - 1], mid, cnt, i, j;
	while (small<big) {
		mid = small + big >> 1;
		cnt = 0;
		j = matrixRowSize - 1;
		for (i = 0; i<matrixRowSize; i++) {
			while (j >= 0 && matrix[i][j]>mid) --j;
			cnt += j + 1;
		}
		if (cnt<k) small = mid + 1;
		else big = mid;
	}
	return big;
}