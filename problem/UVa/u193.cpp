#include <cstdio>
#include <vector>
using namespace std;
int setNum, pointNum, lineNum, maxNum, M, N;
vector<int> tuples[105], answer, tmp;
bool black[105];
void init(int pointNum){
	tmp.clear();
	maxNum = 0;
	for(int i = 0; i < (pointNum+1); i++){
		tuples[i].clear();
		black[i] = false;
	}
}
void backtracking(int n){
	if(n > pointNum){
		if(tmp.size() > maxNum){
			answer = tmp;
			maxNum = answer.size();
		}
		return;
	}
	bool hasBlack = true;
	for(int i = 0; i < tuples[n].size();i++){
		if(black[tuples[n][i]]) hasBlack = false;
	}
	if(hasBlack){
		tmp.push_back(n);
		black[n] = true;
		backtracking(n+1);
		tmp.pop_back();	
	}
	black[n] = false;
	backtracking(n+1);	
}
int main(int argc, char const *argv[]){
	scanf("%d", &setNum);
	for(int i = 0; i < setNum; i++){
		scanf("%d %d", &pointNum, &lineNum);
		init(pointNum);
		for(int j = 0; j < lineNum; j++){
			scanf("%d %d", &M, &N);
			tuples[M].push_back(N);
			tuples[N].push_back(M);
		}
		backtracking(1);
		printf("%d\n%d", maxNum, answer[0]);
		for(int j = 1; j < maxNum; j++){
			printf(" %d", answer[j]);
		}
		printf("\n");
	}
	return 0;
}
