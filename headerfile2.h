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