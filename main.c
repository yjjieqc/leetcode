#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
//#include "headerfile1.h"
//#include "headerfile2.h"
//#include "headerfile3.h"
//#include "headerfile5.h"
//#include "headerfile7.h"
#define debug 1

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// 31. Next Permutation
void nextPermutation(int* nums, int numsSize) {
	int j = numsSize - 1;
	for (; j > 0; j--) {
		if (nums[j - 1] < nums[j]) {
			int k = j;
			while (nums[j - 1] < nums[k] && k < numsSize)
				k++;
			k -= 1;
			int temp = nums[j - 1];
			nums[j - 1] = nums[k];
			nums[k] = temp;
			qsort(nums + j, numsSize - j, sizeof(int), rcmp);
			return;
		}
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	return;
}




// 60. Permutation Sequence

int main()
{
	int num[] = { 1,2,3 };
	int c = 53;
	int d = 0;
	int **b = permute(num, 3, &d);
#if debug
	printf("%d\n", d);
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < 4; j++)
			printf("%2d ", b[i][j]);
		printf("\n");
	}
	printf("\n");
#endif
	system("pause");
	return 0;
}