#include <iostream>

using namespace std;

const string weekday[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int start = 6;
int main(void) {
	int round, m, d;
	cin >> round;
	for (int i = 0; i < round; i++) {
		int days = 0;
		cin >> m >> d;
		for (int j = 1; j < m; j++) {
			days += months[j-1];
		}
		days += d - 1;
		cout << weekday[(days + start) % 7] << endl;
	}
	return 0;
}
