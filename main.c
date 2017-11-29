#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
//#include "headerfile1.h"
//#include "headerfile2.h"
//#include "headerfile3.h"
//#include "headerfile5.h"
//#include "headerfile7.h"
//#define debug 1


int main()
{
	int num[] = { 1,2,3 };
	int c = 3;
	int d = 2;

#if debug
	char *b = getPermutation(c, d);
	//printf("%d\n", d);
	for (int i = 0; i < c; i++) {
		printf("%c", b[i]);
	}
	printf("\n");
#endif
	system("pause");
	return 0;
}