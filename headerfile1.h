#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "otherfunction.h"

#define true 1

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// 
class TwoNumAddSolution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode preHead(0), *p = &preHead;
		int extra = 0;
		while (l1 || l2 || extra) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
			extra = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return preHead.next;
	}
};

// 4. Median of Two Sorted Arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int even = (nums1Size + nums2Size) % 2;
	int line = (nums1Size + nums2Size) / 2;

	double front, behind, result;
	int i = 0, j = 0;
	if (even) {
		while (i + j <= line) {
			if (i <= nums1Size - 1 && j <= nums2Size - 1)
				nums1[i] < nums2[j] ? (result = nums1[i++]) : (result = nums2[j++]);
			else if (i == nums1Size)
				result = nums2[j++];
			else if (j == nums2Size)
				result = nums1[i++];
		}
		return result;
	}
	else {
		while (i + j <= line) {
			behind = front;
			if (i <= nums1Size - 1 && j <= nums2Size - 1)
				nums1[i] < nums2[j] ? (front = nums1[i++]) : (front = nums2[j++]);
			else if (i == nums1Size)
				front = nums2[j++];
			else if (j == nums2Size)
				front = nums1[i++];
		}
		return (front + behind) / 2;
	}
}

// 5. Longest Palindromic Substring
string longestPalindrome(string s) {
	if (s.size() <= 1)
		return s;
	int start = 0, max_len = 1;
	for (int i = 0; i < s.size();) {
		if (s.size() - i <= max_len / 2)
			break;
		int j = i, k = i;
		while (k < s.size() - 1 && s[k + 1] == s[k])
			++k;
		i = k + 1;
		while (k < s.size() - 1 && j >0 && s[k + 1] == s[j - 1]) {
			++k;
			--j;
		}
		int new_len = k - j + 1;
		if (new_len > max_len) {
			start = j;
			max_len = new_len;
		}
	}
	return s.substr(start, max_len);
}

// 8. String to Integer (atoi)
int myAtoi(string str) {
	long long res = 0;
	int flag = 1;
	for (int i = 0; i < str.size();) {
		i = str.find_first_not_of(' ');
		if (str[i] == '-' || str[i] == '+')
			flag = (str[i++] == '-') ? -1 : 1;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
			res = res * 10 + (str[i++] - '0');
		}
	}
	return (res > INT_MAX || res < INT_MIN) ? 0 : (int)res;
// 10. Regular Expression Matching
bool ismatch(char* s, char* p) {
	if (s == NULL || p == NULL)
		return false;
	int m = strlen(s), n = strlen(p);
	bool ** dp = (bool **)malloc((m + 1) * sizeof(bool *));
	for (int i = 0; i < m + 1; i++) {
		dp[i] = (bool *)malloc((n + 1) * sizeof(bool));
		memset(dp[i], false, n + 1);
	}
	dp[0][0] = true;
	for (int i = 0; i < n; i++)
		if (p[i] == '*' && dp[0][i - 1])
			dp[0][i + 1] = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (p[j] == '.' || p[j] == s[i])
				dp[i + 1][j + 1] = dp[i][j];
			else if (p[j] == '*') {
				if (p[j - 1] != s[i] && p[j - 1] != '.')
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
				else
					dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1]);
			}
		}
	}
	bool res = dp[m][n];
	for (int i = 0; i < m + 1; i++)
		free(dp[i]);
	free(dp);
	return res;
}

// 11. Container With Most Water
static inline int max(int a, int b) {
	return a > b ? a : b;
}
static inline int min(int a, int b) {
	return a > b ? b : a;
}
int maxArea(int* height, int heightSize) {
	int left = 0, right = heightSize - 1;
	int maxsum = (right - left)*min(height[left], height[right]);
	while (left < right) {
		if (height[left] < height[right]) {
			left++;
			maxsum = max(maxsum, (right - left)* min(height[left], height[right]));
		}
		else {
			right--;
			maxsum = max(maxsum, (right - left)* min(height[left], height[right]));
		}
	}
	return maxsum;
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

// 16. 3Sum Closest
int threeSumClosest(int* nums, int numsSize, int target) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int i = 0;
	int sum, result;
	if (numsSize>2)
		result = nums[0] + nums[1] + nums[2];
	for (i = 0; i < numsSize - 2; i++) {
		int head = i + 1;
		int tail = numsSize - 1;
		while (head < tail) {
			sum = nums[i] + nums[tail] + nums[head];
			result = fabs(result - target) < fabs(sum - target) ? result : sum;
			int error = sum - target;
			if (error == 0)
				return sum;
			else if (error > 0) {
				tail--;
			}
			else if (error < 0) {
				head++;
			}
		}
	}
	return result;
}

// 19 Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	/*struct ListNode * front,*prev;
	front = head;
	prev = head;
	int count = 0;
	while (front->next != NULL) {
		if (count < n) {
			front = front->next;
			count++;
		}
		else {
			front = front->next;
			prev = prev->next;
		}
	}
	if (count == n) {
		prev->next = prev->next->next;
		return head;
	}
	else {
		return head->next;
	}*/

	ListNode** t1 = &head, *t2 = head;
	for (int i = 1; i < n; i++)
		t2 = t2->next;
	while (t2->next != NULL) {
		t1 = &((*t1)->next);
		t2 = t2->next;
	}
	*t1 = (*t1)->next;
	return head;
}

// 20. Valid Parentheses
bool isValid(char* s) {
	int len = strlen(s);
	char* temp = (char *)malloc(len * sizeof(char));
	int index = 0;
	while (*s) {
		if (*s == '}' && index > 0)
			if (temp[index - 1] == '{')
				index--;
			else
				return false;
		else if (*s == ']' && index > 0)
			if (temp[index - 1] == '[')
				index--;
			else
				return false;
		else if (*s == ')' && index > 0)
			if (temp[index - 1] == '(')
				index--;
			else
				return false;
		else
			temp[index++] = (*s);
		s++;
	}
	free(temp);
	return index == 0;
}

// 22. Generate Parentheses !!OUT TIME LIMIT
char** generateParenthesis(int n, int* returnSize) {
	*returnSize = factorial(2 * n) / (factorial(n + 1) * factorial(n));
	char ** res = (char **)malloc((*returnSize) * sizeof(char *));
	for (int i = 0; i < (*returnSize); i++) {
		res[i] = (char *)malloc((2 * n + 1) * sizeof(char));
	}
	int index = 0, end = 0;
	char * temp = (char *)malloc((2 * n + 1) * sizeof(char));
	temp[2 * n] = '\0';
	addpare(res, temp, n, 0, n, &index, &end);
	free(temp);
	return res;
}

void addpare(char ** res, char * ele, int lp, int rp, int n, int * index, int *end) {
	if (lp == 0 && rp == 0) {
		res[*index] = (char*)memcpy(res[*index], ele, 2 * n + 1);
		res[*index][2 * n] = '\0';
		(*index)++;
		return;
	}
	if (rp > 0) {
		ele[(*end)++] = ')';
		addpare(res, ele, lp, rp - 1, n, index, end);
		(*end)--;
	}
	if (lp > 0) {
		ele[(*end)++] = '(';
		addpare(res, ele, lp - 1, rp + 1, n, index, end);
		(*end)--;
	}
}

// 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode * current, *behind, *front;
	if (head == NULL)
		return head;
	else {
		current = head;
		behind = head;
		front = head;
	}
	while (current && current->next) {
		front = current->next->next;
		behind = current;
		current = current->next;
		if (behind == head)
			head = current;
		current->next = behind;
		if (front&& front->next)
			behind->next = front->next;
		else
			behind->next = front;
		current = front;
	}
	return head;
}

// 25. Reverse Nodes in k - Group
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode * current, *behind, *prev1, *prev2, *front;
	if (head == NULL)
		return head;
	current = behind = prev1 = prev2 = head;
	front = current->next;
	int count = 1;
	int num = 0;
	while (front) {
		while (count < k) {
			if (front) {
				current = front;
				printf("current val is %d\n", current->val);
				front = front->next;
				current->next = behind;
				behind = current;
				if (front) {
					current = front;
				}
				count++;
			}
			else
				break;
		}
		count = 1;
		num++;
		if (num == 1) {
			head = behind;
			prev2 = front;
			prev1->next = NULL;
			if(prev1)
			printf("prev1 val is %d\n", prev1->val);
			if (prev2)
				printf("prev2 val is %d\n", prev2->val);
		}
		else if (num > 2) {
			prev1->next = current;
			prev1 = prev2;
			prev2 = front;
			if (prev1)
				printf("num > 2, prev1 val is %d\n", prev1->val);
			if (prev2)
				printf("num > 2, prev2 val is %d\n", prev2->val);
			else
				printf("prev2 is not exist!");
		}
	}
		return head;
}

// 26. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize) {
	int index1 = 0; 
	int index2 = 0;
	while (index2 < numsSize) {
		//index2++;
		if (nums[index1] == nums[index2])
			index2++;
		else
		{
			index1++;
			nums[index1] = nums[index2];
			index2++;
		}			
	}
	return index1 + 1;
}

// 27. Remove Element
int removeElement(int* nums, int numsSize, int val) {
	int index1 = 0;
	int index2 = 0;
	while (index2 < numsSize) {
		if (nums[index2] == val) {
			index2++;
		}
		else
			nums[index1++] = nums[index2++];
	}
	return index1;
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
			qsort(nums + j, numsSize - j, sizeof(int), cmp);
			return;
		}
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	return;
}

// 32. Longest Valid Parentheses
int longestValidParentheses(char* s) {
	int n = strlen(s), maxlen = 0;
	int * len = (int *)malloc(n * sizeof(int));
	memset(len, 0, sizeof(int) * n);
	for (int i = 1; i < n; i++) {
		if (s[i] == ')'  && s[i - len[i - 1] - 1] == '(')
			if (i - len[i - 1] - 1 > 0)
				len[i] = len[i - 1] + 2 + len[i - len[i - 1] - 2];
			else
				len[i] = len[i - 1] + 2;
		printf("len[%d] = %d\n", i, len[i]);
		maxlen = maxlen > len[i] ? maxlen : len[i];
	}
	return maxlen;
}

// 33. Search in Rotated Sorted Array
int search(int* nums, int numsSize, int target) {
	int i = 0;
	while (i<numsSize) {
		if (nums[i] != target)
			i++;
		else
			return i;
	}
	return -1;
}

//int majorityElement1(int* nums, int numsSize) {
//	int major = nums[0], count = 1;
//	for (int i = 1; i<numsSize; i++) {
//		if (count == 0) {
//			count++;
//			major = nums[i];
//		}
//		else if (major == nums[i]) {
//			count++;
//		}
//		else count--;
//	}
//	return major;
//}

//int majorityElement(int* nums, int numsSize) {
//	srand(unsigned (time(NULL)));
//	while (true) {
//		int index = rand() % numsSize;
//		int majority = nums[index];
//		int counts = 0;
//		for (int i = 0; i < numsSize; i++) {
//			if (nums[i] == majority)
//				counts++;
//			if (counts > numsSize / 2)
//				return majority;
//		}
//	}
//}

//42. Trapping Rain Water
int trap(int* height, int heightSize) {
	int left = 0, right = *height - 1;
	int level = 0;
	int water = 0;
	int lower = 0;
	while (left<right) {
		lower = height[left] < height[right] ? height[left++] : height[right--];
		if (lower > level)
			level = lower;
		water += level - lower;
	}
	return water;
}

// 44. Wildcard Matching
bool isMatch(string s, string p) {
	int indexs = 0, indexp = 0, sinter = 0, star = -1;
	while (indexs < s.length()) {
		if (s[indexs] == p[indexp] || p[indexp] == '?') {
			indexs++;
			indexp++;
			continue;
		}
		if (p[indexp] == '*') {
			star = indexp++;
			sinter = indexs;
			continue;
		}
		if (star != -1) {
			indexp = star + 1;
			indexs = sinter++;
			continue;
		}
		return false;
	}
	while (p[indexp] == '*')
		indexp++;
	return (indexp == p.length());
}

// 45 th
int jump(int* nums, int numsSize) {
	int index = 0;			//jump pointer
	int max_index = 0;		//index of max jump range
	int step = nums[0];		//record of max jump range
	int num_step = 0;		//record times of jumping
	while (index < numsSize - 1) {
		if ((index + nums[index] >= numsSize - 1) || (max_index == numsSize - 1))
			return ++num_step;
		max_index = index + 1;
		for (int i = 1; i < step; i++) {
			if ((nums[max_index] + max_index) < (nums[index + i + 1] + index + i + 1))
				max_index = index + i + 1;
		}
		step = nums[max_index];
		index = max_index;
		num_step++;
	}
	return num_step;
}

// 46. Permutations
int** permute(int* nums, int numsSize, int* returnSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int size = 1, i = 1;
	while (i <= numsSize)
		size *= i++;
	int **result = (int **)malloc(sizeof(int *)*size);
	result[0] = (int *)malloc(sizeof(int)*numsSize);
	memcpy(result[0], nums, sizeof(int)*numsSize);
	i = 1;
	while (i < size) {
		result[i] = (int *)malloc(sizeof(int)* numsSize);
		memcpy(result[i], result[i - 1], sizeof(int)*numsSize);
		int j = numsSize - 1;
		for (; j > 0; j--) {
			if (result[i][j - 1] < result[i][j]) {
				int k = j;
				while (result[i][j - 1] < result[i][k] && k < numsSize)
					k++;
				k -= 1;
				int temp = result[i][j - 1];
				result[i][j - 1] = result[i][k];
				result[i][k] = temp;
				qsort(result[i] + j, numsSize - j, sizeof(int), cmp);
				break;
			}
		}
		i++;
	}
	*returnSize = size;
	return result;
}

// 47. Permutations II
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = 0;
	int size = 1, i = 1;
	while (i <= numsSize)
		size *= i++;
	int **result = (int **)malloc(sizeof(int *)*size);
	result[0] = (int *)malloc(sizeof(int)*numsSize);
	memcpy(result[0], nums, sizeof(int)*numsSize);
	i = 1;
	while (i < size) {
		result[i] = (int *)malloc(sizeof(int)* numsSize);
		memcpy(result[i], result[i - 1], sizeof(int)*numsSize);
		int j = numsSize - 1;
		for (; j > 0; j--) {
			if (result[i][j - 1] < result[i][j]) {
				int k = j;
				while (result[i][j - 1] < result[i][k] && k < numsSize)
					k++;
				k -= 1;
				int temp = result[i][j - 1];
				result[i][j - 1] = result[i][k];
				result[i][k] = temp;
				qsort(result[i] + j, numsSize - j, sizeof(int), cmp);
				(*returnSize) += 1;
				break;
			}
		}
		i++;
	}
	*returnSize = size;
	return result;
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
			for (int p = index; p< n; p++)//使用memmove消耗更多时间
				nums[p] = nums[p + 1];
	}
	free(nums);
	return result;
}

// 66. Plus One
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int *result = (int*)malloc((digitsSize + 1) * sizeof(int));
	memset(result, 0, (digitsSize + 1) * sizeof(int));
	int increase = 1;
	int i = digitsSize;
	while (increase) {
		if (i - 1 >= 0 && digits[i - 1] + increase < 10) {
			result[i] = digits[i - 1] + increase;
			for (int j = i - 1; j > 0; j--)
				result[j] = digits[j - 1];
			increase = 0;
			i--;
		}
		else if (i - 1 >= 0 && digits[i - 1] + increase >= 10) {
			result[i] = digits[i - 1] + increase - 10;
			i--;
		}
		else {
			result[i] = increase;
			increase = 0;
		}
	}
	if (result[0] == 1) {
		*returnSize = digitsSize + 1;
		return result;
	}
	*returnSize = digitsSize;
	return &result[1];
}

// 67. Add Binary
char* addBinary(char* a, char* b) {
	if (a[0] == '0')
		return b;
	else if (b[0] == '0')
		return a;

	int p = strlen(a);
	int q = strlen(b);
	int size = (p > q ? p : q) + 2;
	char * result = (char*)malloc(size * sizeof(char));
	result[size - 1] = '\0';
	int flag = 0, i = 1;
	int * newresult;
	while (p - i >= 0 && q - i >= 0) {
		result[size - 1 - i] = (a[p - i] + b[q - i] + flag) % 2 + '0';
		flag = (((a[p - i] + b[q - i] + flag) / 2) >= '1') ? 1 : 0;
		i++;
		if (p - i < 0)
			goto bislager;
		else if (q - i < 0)
			goto aislager;
	}

aislager:
	while (p - i >= 0) {
		if (flag) {
			result[size - 1 - i] = (a[p - i] + flag) % 2 + '0';
			flag = ((a[p - i] + flag) > '1') ? 1 : 0;
			i++;
		}
		else {
			result[size - 1 - i] = a[p - i];
			i++;
		}
	}
	if (flag) {
		result[0] = '1';
		return result;
	}
	newresult = malloc((size - 1) * sizeof(int));
	memcpy(newresult, result + 1, sizeof(int)*(size - 1));
	free(result);
	return newresult;

bislager:
	while (q - i >= 0) {
		if (flag) {
			result[size - 1 - i] = (b[q - i] + flag) % 2 + '0';
			flag = ((b[q - i] + flag) > '1') ? 1 : 0;
			i++;
		}
		else {
			result[size - 1 - i] = b[q - i];
			i++;
		}
	}
	if (flag) {
		result[0] = '1';
		return result;
	}
	newresult = malloc((size - 1) * sizeof(int));
	memcpy(newresult, result + 1, sizeof(int)*(size - 1));
	free(result);
	return newresult;
}

// 88 th
void merge(int* nums1, int m, int* nums2, int n) {
	int index1 = m - 1;
	int index2 = n - 1;
	for (int i = m + n - 1; i >= 0; i--) {
		if (index1 == -1) {
			nums1[i] = nums2[index2];
			index2--;
		}
		else if (index2 == -1) {
			nums1[i] = nums1[index1];
			index1--;
		}
		else if (nums1[index1] >= nums2[index2]) {
			nums1[i] = nums1[index1];
			index1--;
		}
		else {
			nums1[i] = nums2[index2];
			index2--;
		}
	}
}

// 83. Remove Duplicates from Sorted List
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode * temp = head;
	if (head == NULL)
		return head;
	while (temp->next != NULL) {
		if (temp->val == temp->next->val)
			temp->next = temp->next->next;
		else
			temp = temp->next;
	}
	return head;
}

// 697. Degree of an Array
//int findShortestSubArray(int* nums, int numsSize) {
//	int result [][]
//	for (int i = 0; i < numsSize; i++) {
//
//	}
//}