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

#define INT_MAX__ (((unsigned int)(-1))>>1)

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// 18. 4Sum
/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int size = 10;
	int **result = (int **)malloc(sizeof(int *)* size);
	int i = 0, j, count = 0;
	while (i < numsSize - 3) {
		if (nums[i] * 4 > target)
			break;
		if (i > 0 && nums[i] == nums[i - 1]) {
			i++;
			continue;
		}
		int three_sum = target - nums[i];
		j = i + 1;
		while (j < numsSize - 2) {
			if (nums[j] * 3 > three_sum)
				break;
			if (j > i + 1 && nums[j] == nums[j - 1]) {
				j++;
				continue;
			}
			int two_sum = three_sum - nums[j];
			int left = j + 1, right = numsSize - 1;
			while (left < right) {
				int temp = nums[left] + nums[right];
				int duplicate_left = nums[left];
				int duplicate_right = nums[right];
				if (temp > two_sum) {
					right--;
					while (nums[right] == duplicate_right)
						right--;
				}
				else if (temp < two_sum) {
					left++;
					while (nums[left] == duplicate_left)
						left++;
				}
				else {
					if (count > size) {
						size *= 2;
						result = (int **)realloc(result, sizeof(int *) * size);
					}
					result[count] = (int *)malloc(sizeof(int) * 4);
					result[count][0] = nums[i];
					result[count][1] = nums[j];
					result[count][2] = nums[left];
					result[count][3] = nums[right];
					count++;
					left++;
					while (nums[left] == duplicate_left)
						left++;
					right--;
					while (nums[right] == duplicate_right)
						right--;
				}
			}
			j++;
		}
		i++;
	}
	(*returnSize) = count;
	return result;
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