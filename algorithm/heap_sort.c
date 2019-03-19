#include <stdio.h>
#include <math.h>

#define LEN 10

void print_data(char *msg, int *data);
void heap_sort(int *data);
void swap (int *a, int *b);
void heapify(int *data, int root, int length);

int main(void) {
	int data[LEN], i;
	srand(time(NULL));
	for (i = 0; i < LEN; i++) {
		data[i] = rand()%30 + 1;
	}
	print_data("Before Sorting...", data);
	heap_sort(data);
	print_data("After Sorting...", data);
	return 0;
}

void print_data(char *msg, int *data) {
	int i;
	puts(msg);
	for(i = 0; i < LEN; i++) {
		printf("%d ", data[i]);
	}
	puts("");
}

void heap_sort(int *data) {
	int i;
	/* Build heap tree */
	for (i = floor(LEN/2)-1; i >= 0; i--) {
		heapify(data, i, LEN);
	}
	/* Sorting */
	for (i = LEN-1; i > 0; i--){
		swap((data+i), data);
		heapify(data, 0, i);
	}
}

void swap (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify (int *data, int root, int length) {
	int largest = root,
			left = 2 * root + 1,
			right = 2 * root + 2;
	if (left < length && data[left] > data[largest])
		largest = left;
	if (right < length && data[right] > data[largest])
		largest = right;
	if (largest != root){
		swap((data+root), (data+largest));
		heapify(data, largest, length);
	}
}
