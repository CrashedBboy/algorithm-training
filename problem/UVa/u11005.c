#include <stdlib.h>
#include <stdio.h>

int main(){
	int number, cost[36], row, i, j, k, l;
	scanf("%d", &number);
	for(i = 0;i < number; i++){
		printf("Case %d:\n", (i+1));
		for(j = 0; j < 36; j++){
			scanf("%d", &cost[j]);
		}
		scanf("%d", &row);
		long value[row];
		for(j = 0; j < row; j++){
			scanf("%ld", &value[j]);
		}
		for(j = 0; j < row; j++){
			long min = 2000000000001;
			long price[37];
			for(k = 2; k <= 36; k++){
				price[k] = 0;
				for(l = value[j]; l > 0; l /= k){
					price[k] += cost[l%k];
				}
				if(price[k] < min){
					min = price[k];
				}
			}
			printf("Cheapest base(s) for number %ld:", value[j]);
			for(k = 2; k <= 36; k++){
				if(price[k] == min){ 
					printf(" %d", k);
				}
			}
			printf("\n");
		}
		if(i < (number-1)){
			printf("\n");
		}
	}
}
