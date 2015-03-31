#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	int n, i, tmp;
	char op[5];
	while(1){
		int die[3]={1,2,3}; //top, north, west
		scanf("%d", &n);
		if(n == 0)
			break;
		for(i = 0; i < n; i++){
			scanf("%s", op);
			switch(op[0]){
				case 'n':
					tmp = die[0];
					die[0] = 7 - die[1];
					die[1] = tmp;
					break;
				case 's':
					tmp = die[0];
					die[0] = die[1];
					die[1] = 7 - tmp;
					break;
				case 'w':
					tmp = die[0];
					die[0] = 7 - die[2];
					die[2] = tmp;
					break;
				case 'e':
					tmp = die[0];
					die[0] = die[2];
					die[2] = 7 - tmp;
					break;
			}
		}
		printf("%d\n", die[0]);
	}
	return 0;
};
