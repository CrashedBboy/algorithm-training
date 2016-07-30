#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Pile;

int number, from, to;
string action, preposition;
vector<Pile> piles;
vector<int> position;

void move(int source, int destination) {
	int tmp = piles.at(source).back();
	piles.at(destination).push_back(tmp);
	piles.at(source).pop_back();
	position.at(tmp) = destination;
}

void returnAbove(int n) {
	int pos = position.at(n);
	while (piles.at(pos).size() && piles.at(pos).back() != n) {
		move(pos, piles.at(pos).back());
	}
}

void moveAbove(int from, int to) {
	int source = position.at(from);
	int dest = position.at(to);
	while (piles.at(source).size()) {
		int tmp = piles.at(source).back();
		move(source, piles.size() - 1);
		if (tmp == from) break;
	}
	while (piles.back().size()) {
		move(piles.size() - 1, dest);
	}
}
int main(void) {
	while (cin >> number) {
		for (int i = 0; i <= number; i++) {
			Pile p(1, i);
			piles.push_back(p);
			position.push_back(i);
		}
		while (cin >> action && action != "quit") {
			cin >> from >> preposition >> to;
			if (position.at(from) == position.at(to)) continue;
			if (action == "move") {
				if (preposition == "onto") {
					returnAbove(from);
					returnAbove(to);
					move(position.at(from), position.at(to));
				} else if (preposition == "over") {
					returnAbove(from);
					move(position.at(from), position.at(to));
				}
			} else if (action == "pile") {
				if (preposition == "onto") {
					returnAbove(to);
					moveAbove(from, to);
				} else if (preposition == "over") {
					moveAbove(from, to);
				}
			}
		}
		for (int i = 0; i < number; i++) {
			cout << i << ":";
			for (vector<int>::iterator j = piles.at(i).begin(); j != piles.at(i).end(); j++) {
				cout << " " << *j;
			}
			cout << endl;
		}
		piles.clear();
		position.clear();
	}
	return 0;
}
