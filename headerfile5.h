#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define true 1

// 402. Remove K Digits
string removeKdigits(string num, int k) {
	int m = num.length() - k;
	string res(m, 0);
	int top = 0;
	for (int i = 0; i <= num.length(); i++) {
		while (top && num[i] < res[top - 1] && k > 0) {
			top--;
			k--;
		}
		if (top < m) {
			res[top++] = num[i];
		}
		else
			k--;
	}
	int index = 0;
	while (res[index] == '0')
		index++;
	cout << index << endl;
	string tmp(res, index, m - index);
	return (tmp == "") ? "0" : tmp;
}

// 475. Heaters
int cmp(const void *a, const void *b) {
	return *(const int *)a - *(const int *)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
	qsort(houses, housesSize, sizeof(houses[0]), cmp);
	qsort(heaters, heatersSize, sizeof(heaters[0]), cmp);
	//sort(houses, 0, housesSize - 1);
	//sort(heaters, 0, heatersSize - 1);

	int i = 0, j = 0;
	int max = 0;
	int radius = 0;
	for (i; i < housesSize; i++) {
		if (j < heatersSize - 1) {
			while (fabs(houses[i] - heaters[j]) >= fabs(houses[i] - heaters[j + 1]) && j < heatersSize)
				j++;
			radius = fabs(houses[i] - heaters[j]);
		}
		else
			radius = fabs(houses[i] - heaters[j]);
		max = max > radius ? max : radius;
	}
	return max;
}

// 494. Target Sum
int findTargetSumWays(vector<int>& nums, int S) {
	int count = 0;
	calcsum(nums, S, 0, 0, 1, count);
	calcsum(nums, S, 0, 0, -1, count);
	return count;
}

void calcsum(vector<int>& nums, int S, int temp, int index, int positive, int& count) {
	temp += positive * nums[index];
	if (index == nums.size() - 1) {
		if (temp == S)
			count++;
		return;
	}
	cout << "index: " << index + 1 << "positive or ngative: " << ((positive == 1) ? "P" : "N") << count << endl;
	calcsum(nums, S, temp, index + 1, 1, count);
	calcsum(nums, S, temp, index + 1, -1, count);
}