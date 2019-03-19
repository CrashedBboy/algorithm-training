#include <iostream>

using namespace std;

int main(void) {
	int round;
	cin >> round;
	for (int i = 0; i < round; i++) {
		int len, ptr = -1, count = 0;
		string field;
		cin >> len >> field;
		for (int j = 0; j < len; j++) {
			if (j <= ptr) continue;
			if (field[j] == '#') continue;
			count += 1;
			ptr = j + 2;
		}
		cout << "Case " << i+1 << ": " << count << endl;
	}
	return 0;
}
