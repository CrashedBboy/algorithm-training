#include <stdlib.h>
#include <stdio.h>
float ABS(double a){
	if(a < 0)
		a=0-a;
	return a;
}

int main(){
	float h, m;
	float angle;
	while(1){
		scanf("%f:%f", &h, &m);
		if(h == 0)
		   	break;
		angle = ABS(30*h - (5.5)*m);
		if(angle > 180)
			angle = 360 -angle;
		printf("%.3f\n", angle);
	}
	return 0;
}

