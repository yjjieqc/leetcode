
#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct list_head {
	struct list_head *prev, *next;
};

struct student {
	int age;
	char name[20];
	struct list_head head;
};

void INIT_LIST_HEAD(struct list_head *head)
{
	head->prev = head;
	head->next = head;
}

void __list_add(struct list_head *new, struct list_head *prev, struct list_head
	*next)
{

	prev->next = new;
	new->prev = prev;
	new->next = next;
	next->prev = new;
}

void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head->next);
}

#define list_for_each(p,head)  for((p) = (head)->next;(p)!=(head);(p)=(p)->next)

#define offset(type,member) (size_t)&(((type *)0)->member)

#define container_of(ptr,type,member) \ 
({const typeof(((type *)0)->member) *_mptr = (ptr); \ 
(type *)((char *)(_mptr) - offset(type,member));})

#define list_for_entry(ptr,type,member)        container_of(ptr,type,member)

int main(int argc, char *argv[])
{
	struct list_head head;
	struct list_head *pHead;

	struct student stu1;
	struct student stu2 = {16, "Lili"};
	struct student *stu_entry;

	INIT_LIST_HEAD(&head);

	stu1.age = 17;
	memcpy(stu1.name, "lisi", strlen("lisi"));

	list_add(&stu1.head, &head);
	list_add(&stu2.head, &head);

	int set = offset(struct student, head);
	int * num = (int *)malloc(sizeof(int) * 4);
	printf("%d\n", sizeof(num)/sizeof(num[0]));

	return 0;
}
