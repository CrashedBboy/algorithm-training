#include <stdio.h>
#include <math.h>
#include <time.h>

char table[5000000];

int maxPrime(int n) {
	int k;
	for (k = n-(n+1)%2; k > 1 ; k -= 2){
		if (table[k/2-1])
			return k;
	}
	return 2;
}

int main(void) {
	clock_t start, end;
	double spent;
	start = clock();
	int i, j;
	for(i = 0; i < 5000000; i++){
		table[i] = 1;
	}
	for (i = 3; i < 10000000; i += 2) {
		if(table[i/2-1]) {
			for (j = 3; j*i <= 10000000; j += 2) {
				table[i*j/2-1] = 0;
			}
		}
	}
	int input;
	printf("Number:");
	scanf("%d", &input);
	printf("Biggest Number under %d is %d", input, maxPrime(input));
	end = clock();
	spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time Spent:%lf\n", spent);
	return 0;
}
