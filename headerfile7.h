#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define true 1


// 738. Monotone Increasing Digits
int monotoneIncreasingDigits(int N) {
	string str = to_string(N);
	int rindex = str.size() - 1;
	for (int i = str.size() - 1; i > 0; i--) {
		if (str[i] > str[i - 1])
			continue;
		str[i - 1] -= 1;
		rindex = i;
	}
	for (int i = rindex; i < str.size(); i++)
		str[i] = '9';
	return stoi(str);
}