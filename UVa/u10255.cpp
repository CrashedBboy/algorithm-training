#include <cstdio>
#include <vector>

using namespace std;

typedef struct {
	int x;
	int y;
} Step;

int size, startx, starty;
vector< vector<int> > board;
vector<int> possibleStep;
int dir[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
									{-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
vector<int>::iterator it;

int main(void) {
	while (scanf("%d %d %d\n", &size, &startx, &starty) != EOF) {
		board.resize(size + 1);
		possibleStep.clear();
		travel(step(startx, starty));
	}
	return 0;
}

Step step(int x, int y) {
	Step s;
	s.x = x;
	s.y = y;
	return s;
}

void travel(Step start) {
	board[start.x][start.y] = 1;
	Step current = start;
	for (int i = 2; i < size * size + 1; i++) {
		possible(current, possibleStep);
		int c = possibleStep.size();
		printf("possibleStep[].size = %d\n", c);
		if(c == 0)
			break;
		if(c == 1)
			current = get(ceurrent, 1);
		else
			current = hard(current);
		board[current.x][current.y] = i;
	}
}

void possible(Step current, vector<int> &pos) {
	for(int i = 0; i < 8; i++) {
		Step s = step(current.x + dir[i][0], current.y + dir[i][1]);
		if (isVisitable(s)) {
			pos.push_back(i);
		}
	}
}

Step get(Step current, int number) {
	vector<int>::iterator it = possibleStep.end();
	return step(current.x + dir[*it][0], current.y + dir[*it][1]);
}

Step hard(Step current) {
	vector<int> minPossibleStep;
	possible(get(current, 1), minPossibleStep);

	int min, i;
	for(min = 0, i = 1; i < possibleStep.size(); i++) {
		vector<int> nextPossibleStep;
		Step s = get(current, i + 1);
		possible(s, nextPossibleStep);
		if(nextPossibleStep.size() < minPossibleStep.size){
			min = i;
			minPossibleStep.clear();
			minPossibleStep.assign(nextPossibleStep.begin(), nextPossibleStep.end());
		}
	}

	return get(current, min + 1);
}

bool isVisitable(Step s) {
	return !board[s.x][s.y];
}
