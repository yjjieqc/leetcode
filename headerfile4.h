#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

// 321. Create Maximum Number
class MaxNumSolution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int n1 = nums1.size(), n2 = nums2.size();
		vector<int> res;
		for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1)
			res = max(res, maxNumber(maxNumber(nums1, k1),
				maxNumber(nums2, k - k1)));
		return res;
	}

	vector<int> maxNumber(vector<int>& nums, int k) {
		int drop = nums.size() - k;
		vector<int> out;
		for (int num : nums) {
			while (drop && out.size() && out.back() < num) {
				out.pop_back();
				drop--;
			}
			out.push_back(num);
		}
		out.resize(k);
		return out;
	}

	vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
		vector<int> out;
		while (nums1.size() + nums2.size()) {
			vector<int> & now = nums1 > nums2 ? nums1 : nums2;
			out.push_back(now[0]);
			now.erase(now.begin());
		}
		return out;
	}
};

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