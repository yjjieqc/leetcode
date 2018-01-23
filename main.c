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



int main()
{
	char ** c;
	int * count;
	c = generateParenthesis(6, count);
	for (int i = 0; i < *count; i++) {
		printf("[");
		for (int j = 0; j < 12; j++) {
			printf("%c", c[i][j]);
		}
		printf("]\n");
	}
	free(c);
#if debug

#endif
	system("pause");
	return 0;
}