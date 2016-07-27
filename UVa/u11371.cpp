#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main(void) {
	string input;
	vector<int> number;
	while(cin >> input) {
		long big = 0, small = 0;
		for (int i = 0; i < input.size(); i++) {
			number.push_back(input[i] - '0');
		}
		sort(number.begin(), number.end());
		for (int i = 0; i < number.size(); i++) {
			big += number.at(i) * (long)pow(10, i);
		}
		for (int i = 0; i < number.size(); i++) {
			if (number.at(i) != 0) {
				small += number.at(i) * (long)pow(10, number.size() - 1);
				number.erase(number.begin() + i);
				break;
			}
		}
		for (int i = 0; i < number.size(); i++) {
			small += number.at(i) * (long)pow(10, number.size() - 1 - i);
		}
		cout << big << " - " << small << " = " << big - small << " = 9 * " << (big-small) / 9 << endl;
		number.clear();
	}
	return 0;
}
