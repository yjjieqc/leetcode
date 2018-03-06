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

typedef char * (*GET_VER)();
typedef struct {
	GET_VER getVersion;
}version;

char * mygetver() {
	return "1.01";
}

int main(int argc, char *argv[]) {
	version ver;
	ver.getVersion = &mygetver;
	printf("%s", ver.getVersion());
}