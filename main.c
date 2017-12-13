#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
//#include "otherfunction.h"
//#include "headerfile1.h"
//#include "headerfile2.h"
//#include "headerfile3.h"
//#include "headerfile5.h"
//#include "headerfile7.h"
#define debug 1




int main()
{
	int a[] = { -2,1,-3,4,-1,2,1,-5,4 };
#if debug
	int b = maxSubArray(a, 9);
	printf("%d\n", b);
#endif
	system("pause");
	return 0;
}