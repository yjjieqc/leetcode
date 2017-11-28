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

		}
	}
}

int main()
{
	int num[] = { -4,-3,-2,-1,0,0,1,2,3,4 };
	int c = 0;
	int d = 0;
	int **b = fourSum(num, 10, c, &d);
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