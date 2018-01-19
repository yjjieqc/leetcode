#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define true 1

// 118. Pascal's Triangle
int** generate(int numRows, int** columnSizes) {
	int ** result = (int **)malloc(sizeof(int *) * numRows);
	int * columnSizesArray = (int *)calloc(numRows,sizeof(int));
	int i = 0;
	while (i < numRows) {
		result[i] = (int *)malloc(sizeof(int)* (i + 1));
		columnSizesArray[i] = i + 1;
		for (int j = 0; j < i + 1; j++) {
			if (i > 1 && j > 0 && j < i)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			else
				result[i][j] = 1;
		}
		i++;
	}
	*columnSizes = columnSizesArray;
	return result;
}

// 119. Pascal's Triangle II<First Version>
int* get_Row(int rowIndex, int* returnSize) {
	int *result = (int *)malloc(sizeof(int)* (rowIndex + 1));
	int *line = (int *)malloc(sizeof(int)* (rowIndex));
	for (int i = 0; i < rowIndex; i++)
		line[i] = 1;
	result[0] = 1;
	for (int i = 1; i < rowIndex + 1; i++) {
		for (int j = 0; j < rowIndex - i; j++)
			line[j] = (j == 0) ? 1 : line[j - 1] + line[j];
		result[i] = (i == rowIndex) ? 1 : line[rowIndex - i] + line[rowIndex - i - 1];
	}
	*returnSize = rowIndex + 1;
	free(line);
	return result;
}
// 119. Pascal's Triangle II<First Version>
int* getRow(int rowIndex, int* returnSize) {
	int *result = (int *)malloc(sizeof(int)* (rowIndex + 1));
	memset(result, 0, sizeof(int)* (rowIndex + 1));
	result[0] = 1;
	for (int i = 1; i <= rowIndex; i++) {
		for (int j = i; j > 0; j--) {
			result[j] += result[j - 1];
		}
	}
	*returnSize = rowIndex + 1;
	return result;
}

struct RandomListNode {
	int label;
	struct RandomListNode *next;
	struct RandomListNode *random;	
};

// 121. Best Time to Buy and Sell Stock
int maxProfit(int* prices, int pricesSize) {
	int buy = prices[0], profit = 0;
	for (int p = 1; p < pricesSize; p++) {
		if (prices[p] < buy)
			buy = prices[p];
		profit = (prices[p] - buy) > profit ? prices[p] - buy : profit;
	}
	return profit;
}

// 122. Best Time to Buy and Sell Stock II
int maxProfit(int* prices, int pricesSize) {
	int max = 0;
	for (int i = 1; i < pricesSize - 1; i++) {
		if (prices[i] - prices[i - 1] > 0)
			max += prices[i] - prices[i - 1];
	}
	return max;
}

// 123. Best Time to Buy and Sell Stock III
int maxProfit(int* prices, int pricesSize) {
	int hold1 = INT_MIN, hold2 = INT_MIN;
	int max1 = 0, max2 = 0;
	for (int i = 0; i < pricesSize; i++) {
		max2 = max(max2, hold2 + prices[i]);
		hold2 = max(hold2, max1 - prices[i]);
		max1 = max(max1, hold1 + prices[i]);
		hold1 = max(hold1, -prices[i]);
	}
	return max2;
}

// 138. Copy List with Random Pointer
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	struct RandomListNode * copyhead = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
	struct RandomListNode * ptr = head;
	if (copyhead)
		struct RandomListNode * copyptr = copyhead;
	else
		return NULL;
	if (!head)
		return copyhead;
	copyhead->label = head->label;
	ptr = ptr->next;
	while (ptr)
	{
		struct RandomListNode * temp = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
		temp->label = ptr->label;
		copyptr->next = temp;
		copyptr = copyptr->next;
	}
	ptr = head;
	copyptr = copyhead;
	struct RandomListNode * p = head;
	struct RandomListNode * q = copyhead;
	while (ptr) {
		if (ptr->random) {
			int count = 0;
			for (int i = 0;; i++) {
				if (p != ptr->random) {
					p = p->next;
					count++;
				}
			}
			for (int i = 0; i < count; i++) {
				q = q->next;
			}
			copyhead->random = q;
			p = head;
			q = copyhead;
			ptr = ptr->next;
			copyptr = copyptr->next;
		}
		else {
			ptr = ptr->next;
			copyptr->random = NULL;
			copyptr = copyptr->next;
		}
	}
	return copyhead;
}

// 152. Maximum Product Subarray
int maxProduct(int* nums, int numsSize) {
	int r = nums[0];
	for (int i = 1, imax = r, imin = r; i < numsSize; i++) {
		if (nums[i] < 0) {
			int temp = imin;
			imin = imax;
			imax = temp;
		}
		imax = max(nums[i], imax * nums[i]);
		imin = min(nums[i], imin * nums[i]);
		r = max(r, imax);
	}
	return r;
}

// 188. Best Time to Buy and Sell Stock IV
int maxProfit(int k, int* prices, int pricesSize) {
	if (k > pricesSize / 2) {
		int result = 0;
		for (int i = 1; i < pricesSize; ++i)
			result += max(prices[i] - prices[i - 1], 0);
		return result;
	}
	int * profit = (int *)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
		profit[i] = 0;
	int * hold = (int *)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
		hold[i] = INT_MIN;
	for (int i = 0; i < pricesSize; i++) {
		for (int j = k - 1; j > 0; j--) {
			profit[j] = max(profit[j], hold[j] + prices[i]);
			hold[j] = max(hold[j], profit[j - 1] - prices[i]);
		}
		profit[0] = max(profit[0], hold[0] + prices[i]);
		hold[0] = max(hold[0], -prices[i]);
	}
	int result = 0;
	for (int p = 0; p < k; p++)
		result = result > profit[p] ? result : profit[p];
	free(profit);
	free(hold);
	return result;
}