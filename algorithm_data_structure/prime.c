#include <stdio.h>
#include <math.h>
#include <time.h>
int isPrime(int n) {
	int i;
	int sqrt_n = sqrt(n);
	for (i = 5; i < sqrt_n+1; i += 2) {
		if ( n%i == 0)
			return 0;
	}
	return 1;
}

int maxPrime(int n) {
	int max = 0;
	int i,gap;
	for (i = 5, gap = 2; i < n; i += gap, gap = 6 - gap) {
		if (isPrime(i)) {
			max = i;
		}
	}
	return max;
}

int main(void) {
	clock_t begin, end;
	double time_spent;
	begin = clock();
	int input = 0;
	printf("Number:");
	scanf("%d", &input);
	printf("Max Prime under %d is %d\n", input, maxPrime(input));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Spent:%lf\n", time_spent);
	return 0;
}
