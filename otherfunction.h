#pragma once

#include <stdlib.h>

//a instance of quick sort algorithm
void quick_sort(int *nums, int begin, int end) {
	if (begin >= end)
		return;

	int low = begin, high = end;
	int key = nums[high];

	while (low < high) {
		while (low< high && key >= nums[low]) {
			low++;
		}
		nums[high] = nums[low];
		while (low < high && key <= nums[high]) {
			high--;
		}
		nums[low] = nums[high];
	}
	nums[low] = key;
	sort(nums, begin, low - 1);
	sort(nums, low + 1, end);
}

//function used in qsort for ordring.
int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int rcmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

int factorial(int a) {
	if (a == 0 || a == 1)
		return 1;
	else
		return factorial(a - 1)*a;
}


int firstBadVersion(int n) {
	int left, right;
	while (left<right) {
		int mid = (left + right) / 2;
		if (isBadVersion(mid)) {
			if (isBadVersion(mid - 1))
				right = mid;
			else
				return mid;
		}
		else
			left = mid + 1;
	}
}