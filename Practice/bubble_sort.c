#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *data);
void print_data(char *msg, int *data);

int main(void) {
	int data[10], i;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		data[i] = rand() % 20 + 1;
	}
	print_data("Before Sorting...", data);
	bubble_sort(data);
	print_data("After Sorting...", data);
	return 0;
}

void bubble_sort(int *data){
	int i, j;
	for (i = 0; i < 10; i++) {
		int swap = 0;
		for (j = 0; j < (9-i); j++) {
			if (data[j] > data[j+1]) {
				int tmp;
				tmp = data[j+1];
				data[j+1] = data[j];
				data[j] = tmp;
				swap = 1;
			}
		}
		if (!swap)
			break;
	}
}

void print_data(char *msg, int *data) {
	int i;
	puts(msg);
	for (i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	puts("");
}
