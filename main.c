#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
//#include "otherfunction.h"
//#include "headerfile1.h"
//#include "headerfile2.h"
//#include "headerfile3.h"
//#include "headerfile5.h"
//#include "headerfile7.h"
#define debug 1


/* Definition for singly-linked list. */
typedef struct ListNode {
	int val;
	struct ListNode *next;
}node;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	node *res = (node*)malloc(sizeof(node));
	res->val = INT_MIN;
	node *temp;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			temp = l1->next;
			res->next = l1;
			l1 = l1->next;
		}
		else {
			res->next = l2;
			l2 = l2->next;
		}
		while (l1) {
			res->next = l1;
			l1 = l1->next;
		}
		while (l2) {
			res->next = l2;
			l2 = l2->next;
		}
	}
	return res->next;
}

void build(node * p, node *q) {
	//node *p = head1, *q = head2;
	for (int i = 1; i < 4; i++) {
		node * new_node1 = (node*)malloc(sizeof(node));
		node * new_node2 = (node*)malloc(sizeof(node));
		new_node1->val = 2 * i;
		new_node2->val = 2 * i + 1;
		p->next = new_node1;
		q->next = new_node2;
		p = p->next;
		q = q->next;
	}
}

void delete_node(node *head) {
	if (head)
		delete_node(head->next);
	else
		return;
	free(head);
}

void print_list(node *head) {
	while (head) {
		printf("  %d", head->val);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	node *l1 = (node *)malloc(sizeof(node));
	node *l2 = (node *)malloc(sizeof(node));
	printf("%p\n", l1);
	build(l1, l2);
	node *temp = l1;
	for (int i = 1; i < 4; i++) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf(l1);
	printf(l2);
#if debug

#endif
	delete_node(l1);
	delete_node(l2);
	system("pause");
	return 0;
}