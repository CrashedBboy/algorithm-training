#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void radix_sort(int *data, int digit);
int main(void){
	int digit, data[10], i;
	printf("Max digit:");
	scanf("%d", &digit);
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		data[i] = (rand() % ((int)pow(10, digit) + 1));
	}
	puts("Before Sorting...");
	for (i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	puts("");
	radix_sort(data, digit);
	puts("After Sorting...");
	for (i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	puts("");
	return 0;
}

void radix_sort(int *data, int digit) {
	int container[10][10] = {0},
			order[10] = {0},
			i, j;
	for (i = 0; i < digit; i++) {
		for (j = 0; j < 10; j++) {
			int lsd = (data[j]/(int)pow(10, i))%10;
			container[lsd][order[lsd]] = data[j];
			order[lsd]++;
		}
		int k = 0;
		for (j = 0; j < 10; j++) {
			int l;
			for (l = 0; l < order[j]; l++, k++){
				data[k] = container[j][l];
			}
			order[j] = 0;
		}
	}
}
