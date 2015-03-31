#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const int MAX = 10001;
void initialize(char *array){
	int counter;
	for(counter = 0; counter < MAX; counter++){
		*(array+counter) = 'N';
	}
}

void borrow(int bitValue,int index, char *array){
	if(bitValue >= 0){
		*(array+index) = (char)(((int)'0') + bitValue);
		return;
	}else if(bitValue < 0){
		bitValue += 10;
		*(array+index) = (char)(((int)'0') + bitValue);
		int buffer = *(array+index-1) - '0';
		buffer -= 1;
		*(array+index-1) = (char)(((int)'0') + buffer);
		borrow(buffer, index - 1, array);
	}
}

int main(int argc, char *argv[]){
	char earnString[MAX], spentString[MAX];
	int number, i, j, k, get, lost;
	scanf("%d", &number);
	for(i = 0; i < number; i++){
		int earnBit, spentBit, buffer;
		get = 0;
		lost = 0;
		int meetHead = 0;
		initialize(earnString);
		initialize(spentString);
		scanf("%s %s", earnString, spentString);
		for(earnBit = 0; earnBit < MAX; earnBit++){
			if(earnString[earnBit] == 'N'){ break;}
		}
		for(spentBit = 0; spentBit < MAX; spentBit++){
			if(spentString[spentBit] == 'N'){ break;}
		}
		if(earnBit > spentBit){
			get = 1;
		}else if(spentBit > earnBit){
			lost = 1;
		}else{
			for(j = 0; j < earnBit; j++){
				int earn , spent;
				earn = earnString[j] - '0';
				spent = spentString[j] - '0';
				if(earn > spent){
					get = 1;
					break;
				}else if(spent > earn){
					lost = 1;
					break;
				}
			}
		}
		if(get == 1){
			for (j = (earnBit-1), k = (spentBit-1); k >= 0; j--, k--){
				int earnBuffer = (earnString[j]-'0');
				int spentBuffer = (spentString[k]-'0');
				int balanceBuffer = earnBuffer - spentBuffer;
				borrow(balanceBuffer, j , earnString);
			}
			for(j = 0; j < (earnBit-1); j++){
				if(earnString[j] != '0' && meetHead == 0){
					meetHead = 1;
				}
				if(meetHead != 0){
					printf("%c", earnString[j]);
				}
			}
		}else if(lost == 1){
			for (j = (spentBit-1), k = (earnBit-1); k >= 0; j--, k--){
				int spentBuffer = (spentString[j]-'0');
				int earnBuffer = (earnString[k]-'0');
				int balanceBuffer = spentBuffer - earnBuffer;
				borrow(balanceBuffer, j , spentString);
			}
			printf("-");
			for(j = 0; j < (spentBit-1); j++){
				if(spentString[j] != '0' && meetHead == 0){
					meetHead = 1;
				}
				if(meetHead != 0){
					printf("%c", spentString[j]);
				}
			}
		}else{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}

