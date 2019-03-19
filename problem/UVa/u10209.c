#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const double pi = 3.141592653589793;
int main(void){
	double a, x, y, z;
	while(scanf("%lf", &a) != EOF){
		z = (1 - sqrt(3)/4 - pi/6)*a*a;
		y = (1 - pi/4)*a*a - 2*z;
		x = a*a - 4*y - 4*z;
		printf("%.3lf %.3lf %.3lf\n", x, 4*y, 4*z);
	}
	return 0;
}
