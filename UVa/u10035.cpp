#include <iostream>
#include <math.h>

using namespace std;

int main() {
	while (true) {
		int a, b, carry = 0, digit_a, digit_b, digit_carry = 0;
		cin >> a;
		cin >> b;
		if (a == 0 && b == 0) break;
		digit_a = (int)log10(a);
		digit_b = (int)log10(b);
		int max = (digit_a > digit_b)? digit_a : digit_b;
		for (int i = 0; i <= max; i++) {
			int da = (a % (int)pow(10, i+1)) / pow(10, i);
			int db = (b % (int)pow(10, i+1)) / pow(10, i);
			int digit_sum = da + db + digit_carry;
			if (digit_sum > 9) {
				carry += 1;
				digit_carry = 1;
			}
		}
		if (carry == 0) {
			cout << "No carry operation." << endl;
		} else {
			cout << carry << " carry operations." << endl;
		}
	}
	return 0;
}
