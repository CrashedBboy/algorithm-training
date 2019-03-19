#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {
	int x;
	int y;
} Step;

int size, startx, starty, finalx, finaly;
vector< vector<int> > board;
vector<int> possibleStep;
vector<int>::iterator it;
int dir[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

Step step(int, int);
bool travel(Step);
void possible(Step, vector<int>&);
Step get(Step, int);
Step hard(Step);
bool isVisitable(Step);
void print_solution();

int main(void) {
	while (scanf("%d %d %d", &size, &startx, &starty) != EOF) {
		board.resize(size + 1);
		for (int i = 1; i < board.size(); i++) {
			board[i].assign(size + 1, 0);
		}
		possibleStep.clear();
		if(travel(step(startx, starty)) && abs((finalx - startx) * (finaly - starty)) == 2){
				print_solution();
		} else {
			printf("No Circuit Tour.\n");
		}
	}
	return 0;
}

Step step(int x, int y) {
	Step s;
	s.x = x;
	s.y = y;
	return s;
}

bool travel(Step start) {
	board[start.x][start.y] = 1;
	Step current = start;
	for (int i = 2; i < size * size + 1; i++) {
		possible(current, possibleStep);
		int c = possibleStep.size();
		if(c == 0)
			return false;
		if(c == 1)
			current = get(current, 1);
		else
			current = hard(current);
		board[current.x][current.y] = i;
	}
	finalx = current.x;
	finaly = current.y;
	return true;
}

void possible(Step current, vector<int> &pos) {
	pos.clear();
	for(int i = 0; i < 8; i++) {
		Step s = step(current.x + dir[i][0], current.y + dir[i][1]);
		if (isVisitable(s)) {
			pos.push_back(i);
		}
	}
}

Step get(Step current, int number) {
	int i = possibleStep[number - 1];
	Step s = step(current.x + dir[i][0], current.y + dir[i][1]);
	return s;
}

Step hard(Step current) {
	vector<int> minPossibleStep;
	possible(get(current, 1), minPossibleStep);

	int min, i;
	for(min = 0, i = 1; i < possibleStep.size(); i++) {
		vector<int> nextPossibleStep;
		Step s = get(current, i + 1);
		possible(s, nextPossibleStep);
		if(nextPossibleStep.size() < minPossibleStep.size()){
			min = i;
			minPossibleStep.clear();
			minPossibleStep.assign(nextPossibleStep.begin(), nextPossibleStep.end());
		}
	}
	return get(current, min + 1);
}

bool isVisitable(Step s) {
	return s.x <= size && s.x > 0 && s.y <= size && s.y > 0 && board[s.x][s.y] == 0;
}

void print_solution() {
	for(int i = 1; i <= size; i++) {
		for(int j = 1; j <= size; j++) {
			printf("%5d", board[i][j]);
		}
		printf("\n");
	}
}
