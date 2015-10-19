#include <stdio.h>
#include <stdlib.h>

#define LEN 10

void print_data(char *msg, int *data);
void quick_sort(int *data, int left, int length);
void swap(int *data, int a, int b);

int main (void) {
	int data[LEN], i;
	srand(time(NULL));
	for (i = 0; i < LEN; i++) {
		data[i] = (rand() % 1000) + 1;
	}
	print_data("Before Sorting ...", data);
	quick_sort(data, 0, 10);
	print_data("After Sorting ...", data);
	return 0;
}

void print_data (char *msg, int *data) {
	int i;
	puts(msg);
	for (i = 0; i < LEN; i++) {
		printf("%d ", data[i]);
	}
	puts("");
}

void quick_sort (int *data, int left, int length) {
	if (length < 2) 
		return;
	int pivot = left + length - 1;
	int i;
	int j = left;
	for (i = left; i < pivot; i++) {
		if (data[i] < data[pivot]) {
			swap(data, j, i);
			j ++;
		}
	}
	swap(data, pivot, j);
	quick_sort(data, left, j - left);
	quick_sort(data, j + 1, left + length - j -1);
}

void swap(int *data, int a, int b) {
	int tmp = data[b];
	data[b] = data[a];
	data[a] = tmp;
}
