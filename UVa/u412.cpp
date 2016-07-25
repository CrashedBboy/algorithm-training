#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
	while ((a %= b) && (b %= a));
	return a+b;
}

int main(void) {
	int n, data[50];
	while (cin >> n && n != 0) {
		int coprime = 0;
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (gcd(data[i], data[j]) == 1)
					coprime += 1;
			}
		}
		if (coprime == 0)
			cout << "No estimate for this data set." << endl;
		else
			cout << fixed << setprecision(6) << sqrt((float)((n * (n-1) * 6) / 2) / (float)coprime ) << endl;
	}
	return 0;
}
