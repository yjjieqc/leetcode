#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define true 1

// 475. Heaters
int cmp(const void *a, const void *b) {
	return *(const int *)a - *(const int *)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
	qsort(houses, housesSize, sizeof(houses[0]), cmp);
	qsort(heaters, heatersSize, sizeof(heaters[0]), cmp);
	//sort(houses, 0, housesSize - 1);
	//sort(heaters, 0, heatersSize - 1);

	int i = 0, j = 0;
	int max = 0;
	int radius = 0;
	for (i; i < housesSize; i++) {
		if (j < heatersSize - 1) {
			while (fabs(houses[i] - heaters[j]) >= fabs(houses[i] - heaters[j + 1]) && j < heatersSize)
				j++;
			radius = fabs(houses[i] - heaters[j]);
		}
		else
			radius = fabs(houses[i] - heaters[j]);
		max = max > radius ? max : radius;
	}
	return max;
}