#include <stdlib.h>
#include <stdio.h>

int main(){
	int times, i, j, up, down, sum;
	scanf("%d", &times);
	for(i = 0; i < times; i++){
		sum = 0;
		scanf("%d", &down);
		scanf("%d", &up);
		if(down%2){
			for(j = down; j <= up; j+=2){
				sum += j;
			}
		}else{
			for(j = (down+1); j <= up; j+=2){
				sum += j;
			}
		}
		printf("Case %d: %d\n", (i+1), sum);
	}
	return 0;
}

