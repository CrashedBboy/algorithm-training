#include <iostream>
#include <vector>

using namespace std;
typedef vector<string> pile;
vector<pile> card;

bool is_match(int a, int b) {
	string sa = card.at(a).back();
	string sb = card.at(b).back();
	return (sa[0] == sb[0] || sa[1] == sb[1]);
}

void move(int from, int to) {
	card.at(to).push_back(card.at(from).back());
	card.at(from).pop_back();
	if (card.at(from).empty())
		card.erase(card.begin() + from);
}

int main(void) {
	string buf;
	card.reserve(52);
	while (true) {
		cin >> buf;
		if (buf == "#")
			return 0;
		pile p(1, buf);
		card.push_back(p);
		for (int i = 1; i < 52; i++) {
			cin >> buf;
			pile p(1, buf);
			card.push_back(p);
		}
		for (int i = 0; i < card.size(); i++) {
			if (i >= 3 && is_match(i, i - 3)) {
				move(i, i-3);
				i -= 4;
			} else if ( i >= 1 && is_match(i, i - 1)) {
				move(i, i-1);
				i -= 2;
			}
		}
		string plural = (card.size() == 1)? "" : "s";
		cout << card.size() << " pile" << plural << " remaining:";
		for (int i = 0; i < card.size(); i++) {
			cout << " " << card.at(i).size();
		}
		cout << endl;
		card.clear();
	}
	return 0;
}
