#include <stdlib.h>
#include <stdio.h>
int main(){
	long long me, op;
	while(scanf("%lld %lld", &me, &op) != EOF){
		printf("%lld\n", op>me? op - me: me - op);
	}
	return 0;
}

