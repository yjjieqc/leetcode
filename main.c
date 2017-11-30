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

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int *result = (int*)calloc(2, sizeof(int));
	result[0] = result[1] = -1;
	int left = 0;
	int right = numsSize - 1;
	int m, flag;
	if (numsSize == 0)
		return result;
	while (left <= right)
	{
		m = (left + right) / 2;
		if (left == right)
			break;
		if (nums[m] < target)
			left = m + 1;
		else
			right = m;
	}
	if (target == nums[m])
		result[0] = m;
	else
		return result;
	for (left = m, right = numsSize - 1; left <= right;)
	{
		m = (left + right) / 2;
		flag = (left + right) % 2;
		if (flag)
			++m;
		if (left == right)
			break;
		if (nums[m] > target)
			right = m - 1;
		else
			left = m;
	}
	result[1] = m;
	return result;
}

int main()
{
	int num[] = { 1,4 };
	int a = 4;
	int d = 2;

#if debug
	int * b = searchRange(num, 2, a, &d);
	for (int i = 0; i < d; i++) {
		printf("%d", b[i]);
	}
	printf("\n");
#endif
	system("pause");
	return 0;
}