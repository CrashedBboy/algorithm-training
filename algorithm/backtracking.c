/****************************
List all possible permutation of char a, b, c
*****************************/
#include <stdio.h>
#include <stdlib.h>

int s[3] = {'a', 'b', 'c'};
char sol[3];
int used[3];

void backtracking(int n, int N){
	int i;
	if(n == N){
		for(i = 0; i < N;i++){
			printf("%c ", sol[i]);
		}
		printf("\n");
		return;
	}
	for(i = 0; i < N; i++){
		if(!used[i]){
			used[i] = 1;
			sol[n] = s[i];
			backtracking(n+1, N);
			used[i] = 0;
		}
	}
}

int main(){
	int i;
	for(i = 0; i < 3; i++){
		used[i] = 0;
	}
	backtracking(0, 3);
	return 0;
}
