#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	vector<int> power, shutdown;
	power.reserve(100);
	shutdown.reserve(100);
	while (cin >> n && n != 0) {
		for (int i = 2; i < n; i++) {
			power.clear();
			shutdown.clear();
			for (int j = 1; j < n; j++) {
				power.push_back(j);
			}
			int ptr = -1;
			while (power.size()) {
				ptr = (ptr + i) % power.size();
				int tmp = power.at(ptr);
				shutdown.push_back(tmp);
				power.erase(power.begin() + ptr);
				ptr -= 1;
				if (tmp == 12) break;
			}
			if (shutdown.back() == 12 && shutdown.size() == n - 1) {
				cout << i << endl;
			}
		}
	}
	return 0;
}
