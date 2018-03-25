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
	char s = 'a';
	char t = '\n';
	printf("char s %s a alpha!\n", isalpha(s) ? "is" : "is not");
	printf("char t %s a alpha!\n", isalpha(t) ? "is" : "is not");
#if debug

#endif
	system("pause");
	return 0;
}