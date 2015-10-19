#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 10

void print_data(char *msg, int *data);
void merge_sort(int *data, int start, int end);

int main(void) {
	int data[LEN], i;
	srand(time(NULL));
	for(i = 0; i < LEN; i++) {
		data[i] = (rand() % 100) + 1;
	}
	print_data("Before sorting ...", data);
	merge_sort(data, 0, LEN - 1);
	print_data("After sorting ...", data);
	return 0;
}

void print_data(char *msg, int *data) {
	puts(msg);
	int i;
	for(i = 0; i < LEN; i++) {
		printf("%d ", data[i]);
	}
	puts("");
}

void merge_sort(int *data, int start, int end) {
	if((end-start) < 2) {
		if(data[start] > data[end]) {
			int tmp = data[end];
			data[end] = data[start];
			data[start] = tmp;
		}
		return;
	}
	int center = (int)floor((start + end) / 2);
	merge_sort(data, start, center);
	merge_sort(data, center + 1, end);
	int h1 = start, h2 = center + 1, h3 = 0, tmp[LEN], i;
	while (h1 <= center && h2 <= end) {
		if (data[h1] <= data[h2]) {
			tmp[h3] = data[h1];
			h1 += 1;
		} else {
			tmp[h3] = data[h2];
			h2 += 1;
		}
		h3 += 1;
	}
	if(h1 <= center){
		for (i = h1; i <= center; i++) {
			tmp[h3] = data[i];
			h3 += 1;
		}
	} else {
		for (i = h2; i <= end; i++) {
			tmp[h3] = data[i];
			h3 += 1;
		}
	}
	for (i = start, h3 = 0; i <= end; i++, h3++) {
		data[i] = tmp[h3];
	}
}
