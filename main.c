#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "headerfile1.h"
//#include "headerfile2.h"
//#include "headerfile3.h"
//#include "headerfile5.h"
//#include "headerfile7.h"
#define debug 1



int main()
{
	int num[] = {1,2,3,4,5,6,7,8,9,10};
	int b = 27;
	int c = threeSumClosest(num, sizeof(num) / sizeof(int), b);
#if debug
		//for (int i = 0; i < b; i++)
		//	printf("%d ", a[i]);
		//printf("\n");
	printf("%d\n", c);
#endif
	return 0;
}