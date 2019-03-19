#include <stdio.h>

int main(){
	int m, n, r;
	printf("A(bigger) :");
	scanf("%d", &m);
	printf("B(smaller) :");
	scanf("%d", &n);
	r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	printf("Result: %d\n", n);
	return 0;
}
