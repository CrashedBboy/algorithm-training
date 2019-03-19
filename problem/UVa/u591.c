#include <stdio.h>

int main(void) {
	int h[50], round = 1;
	while (1) {
		int num, i, aver, ans = 0, sum = 0;
		scanf("%d", &num);
		if (num == 0) break;
		for (i = 0; i < num; i++) {
			scanf("%d", (h+i));
			sum += h[i];
		}
		aver = sum / num;
		for (i = 0; i < num; i++) {
			int diff = aver - h[i];
			if (diff > 0) {
				ans += diff;
			}
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", round++, ans);
	}
	return 0;
}
