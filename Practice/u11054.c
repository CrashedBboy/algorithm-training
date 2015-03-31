#include <stdio.h>
#include <stdlib.h>

int main(){
	while(1){
		int number;
		scanf("%d", &number);
		if(number == 0) break;
		int i, money[number];
		long long total = 0;
		for(i = 0; i < number; i++){
			scanf("%d", &money[i]);
		}
		for(i = 0; i < number; i++){
			total += abs(money[i]);
			money[i+1] += money[i];
		}
		printf("%lld\n", total);
	}
	return 0;
}
