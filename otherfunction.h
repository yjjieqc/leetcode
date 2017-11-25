#pragma once

#include <stdlib.h>

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
