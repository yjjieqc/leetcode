#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define true 1

struct ListNode {
	int val;
	struct ListNode *next;
};

// 203. Remove Linked List Elements
//struct ListNode* removeElements(struct ListNode* head, int val) {
//	struct ListNode* temp = head;
//	while (temp&&temp->val == val) {
//		temp = temp->next;
//		head = temp;
//	}
//	while (temp && temp->next != NULL) {
//		if (temp->next->val == val)
//			temp->next = temp->next->next;
//		else
//			temp = temp->next;
//	}
//	return head;s
//}

// 209. Minimum Size Subarray Sum
int minSubArrayLen(int s, int* nums, int numsSize) {
	int sum = 0, count = 0, i = 0, j = 0;
	if (numsSize == 0)
		return 0;
	else
		sum += nums[0];
	while (j<numsSize) {
		if (sum >= s) {
			count = (count == 0 || count > j - i + 1) ? j - i + 1 : count;
			sum -= nums[i];
			i++;
		}
		else {
			j++;
			sum += nums[j];
		}
	}
	return count;
}

// 234. Palindrome Linked List
bool isPalindrome(struct ListNode* head) {
	struct ListNode *fast = head, *slow = head;
	struct ListNode *temp = NULL;
	struct ListNode *reverse = NULL;

	while (fast && fast->next) {
		temp = reverse;
		reverse = slow;
		slow = slow->next;
		fast = fast->next->next;
		reverse->next = temp;
		if (temp == head)	//没有这个if出现循环指针，报错内存泄漏
			temp->next = NULL;
		if (fast && fast->next == NULL) {
			slow = slow->next;
			break;
		}
	}
	while (slow&& reverse) {
		if (slow->val != reverse->val)
			return false;
		slow = slow->next;
		reverse = reverse->next;
	}
	return true;
}

// 283. Move Zeroes
void moveZeroes(int* nums, int numsSize) {
	int index1 = 0;
	int index2 = 0;
	while (index2 < numsSize) {
		if (nums[index2] == 0) {
			index2++;
		}
		else
			nums[index1++] = nums[index2++];
	}
	for (int i = index1; i < numsSize; i++)
		nums[i] = 0;
	return;
}