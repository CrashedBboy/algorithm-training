#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void) {
	double a, b, c;
	while (cin >> a >> b >> c) {
		double s = (a + b + c) / 2;
		double tri = sqrt(s * (s - a) * (s - b) * (s - c));
		double outcir_r = (a * b * c) / (4 * tri);
		double incir_r = 2 * tri / (a + b + c);
		cout << fixed << setprecision(4) << (outcir_r * outcir_r * M_PI - tri) << " " << (tri - incir_r * incir_r * M_PI) << " " << incir_r * incir_r * M_PI << endl;
	}
	return 0;
}
