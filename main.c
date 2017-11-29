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

int cal_factorial(int a) {
	if (a == 0 || a == 1)
		return 1;
	else
		return cal_factorial(a - 1)*a;
}

// 60. Permutation Sequence
char* getPermutation(int n, int k) {
	int * nums = (int *)malloc(sizeof(int)*n);
	char * result = (char *)malloc(sizeof(char)*(n + 1));
	result[n] = '\0';
	for (int i = 0; i < n; i++)
		nums[i] = i + 1;
	int j = 0;
	k--;
	while (n > 0) {
		n--;
		int val = cal_factorial(n);
		int index = k / val;
		k = k % val;
		result[j++] = ((char)nums[index] + '0');
		if (index != n)
			memmove(nums + index, nums + index + 1, (n - index) * sizeof(int));
	}
	free(nums);
	return result;
}

int main()
{
	int num[] = { 1,2,3 };
	int c = 3;
	int d = 2;

#if debug
	char *b = getPermutation(c, d);
	//printf("%d\n", d);
	for (int i = 0; i < c; i++) {
		printf("%c", b[i]);
	}
	printf("\n");
#endif
	system("pause");
	return 0;
}