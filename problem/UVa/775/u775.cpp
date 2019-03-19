#include <cstdio>
#include <vector>

using namespace std;

vector< vector<bool> > adjacent;
vector<int> solution;
vector<bool> visit;
int number;
char s[20];
bool solve;

void print_solution(){
	for (int i = 1; i <= number; i++) {
		printf("%d ", solution[i]);
	}
	printf("%d\n", solution[1]);
}

void backtrack(int target) {
	int x = solution[target - 1];
	if (target == number + 1) {
		int y = solution[1];
		if (adjacent[x][y]) {
			solve = true;
		}
		return;
	}
	for (int y = 1; y <= number; y++) {
		if (adjacent[x][y] && !visit[y]) {
			solution[target] = y;
			visit[y] = true;
			backtrack(target + 1);
			visit[y] = false;
		}
	}
}

int main (void) {
	int v1, v2;
	char trash;
	while (true) {
		if (scanf("%d\n", &number) == -1) break;
		adjacent.resize(number + 1);
		solution.resize(number + 1);
		visit.resize(number + 1);
		while (gets(s) && s[0] != '%') {
			sscanf(s, "%d %d", &v1, &v2);
			adjacent[v1][v2] = true;
			adjacent[v2][v1] = true;
		}
		for (int i = 1; i <= number; i++) {
			for (int j = 1; j <= number; j++) {
			}
		}
		visit[1] = true;
		solution[1] = 1;
		solve = false;
		backtrack(2);
		if (solve)
			print_solution();
		else
			printf("N\n");
		solve = false;
	}
}
