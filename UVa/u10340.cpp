#include <iostream> 
using namespace std; 

int main() { 
	string s, t;
	while (cin >> s >> t) {
		int ptr = -1;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == s[ptr + 1]) 
				ptr += 1;
		}
		if (ptr + 1 == s.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0; 
}
