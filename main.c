#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "uthash.h"
//#include "otherfunction.h"
//#include "headerfile1.h"
//#include "headerfile2.h"
//#include "headerfile3.h"
//#include "headerfile5.h"
//#include "headerfile7.h"
#define debug 1


struct numc {
	int key;
	int count;
	UT_hash_handle hh;
};

struct numc *users = NULL;

void add_user(int user_id, int count) {
	struct numc *s;

	s = malloc(sizeof(struct numc));
	s->key = user_id;
	s->count = 1;
	HASH_ADD_INT(users, key, s);
}
struct my_struct *find_user(int user_id) {
	struct my_struct *s;

	HASH_FIND_INT(users, &user_id, s);  /* s: output pointer */
	return s;
}
void delete_user(struct numc * user) {
	HASH_DEL(users, user);
	free(user);
}
void delete_all() {
	struct my_struct *current_user, *tmp;

	HASH_ITER(hh, users, current_user, tmp) {
		HASH_DEL(users, current_user);  /* delete it (users advances to next) */
		free(current_user);             /* free it */
	}
}

int findShortestSubArray(int* nums, int numsSize) {

}



int main()
{
	int a[] = { 1,4,2,5,7,2,9 };
#if debug


#endif
	system("pause");
	return 0;
}