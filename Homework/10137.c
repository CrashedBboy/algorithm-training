#include <stdlib.h>
#include <stdio.h>
#include <float.h>
int compfunc(const void *a, const void *b){return (*(int*)b - *(int*)a);}
int main(){
	int counter, number;
	while(scanf("%d", &number) && number != 0){
		int money[number];
		int total = 0;
		double buffer;
		for(counter = 0; counter < number; counter++){
			scanf("%lf", &buffer);
			money[counter] = (buffer+0.000001) * 100;
			total += money[counter];
		}
		qsort(money, number, sizeof(int), compfunc);
		int poor = total%number;
		int average = total/number;
		int totalShift = 0;
		for(counter = 0; counter < poor; counter++){
			totalShift += abs(average-money[counter] +1);
		}
		for(counter = poor; counter < number; counter++){
			totalShift += abs(average-money[counter]);
		}
		totalShift /= 2;
		printf("$%d.%02d\n",(totalShift/100),(totalShift%100));
	}
	return 0;
}
