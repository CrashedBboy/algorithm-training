#include <iostream>
#include "string.h"

using namespace std;

int main(void) {
	long long int dp[30001] = {1};
	int coin[5] = {1, 5, 10, 25, 50};
	for (int i = 0; i < 5; i++) {
		for (int j = coin[i]; j < 30001; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	int n;
	while (cin >> n) {
		if (dp[n] == 1)
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		else
			cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
	}
	return 0;
}
