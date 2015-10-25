#include <cstdio>
#include <algorithm>
using namespace std;

struct Point {
	int x, y, id, rank;
	Point(int a = 0, int b = 0, int c = 0):
		x(a), y(b), id(c), rank(0) {}
	bool operator<(const Point &a) const {
		if(x != a.x)
			return x < a.x;
		else
			return y > a.y;
	}
};

Point data[100], tmp[100];
void dc_merge(int, int, int);
void dc(int, int);

int main(void) {
	int output[100], number, x, y;
	while(scanf("%d", &number) == 1) {
		for(int i = 0; i < number; i++) {
			scanf("%d %d", &x, &y);
			data[i] = Point(x, y, i);
		}
		sort(data, data + number);
		dc(0, number - 1);
		for(int i = 0; i < number; i++) {
			output[data[i].id] = data[i].rank;
		}
		for(int i = 0; i < number; i++) {
			printf("%d \n", output[i]);
		}
	}
	return 0;
}

void dc(int left, int right) {
	if(left >= right)
		return;
	int middle = (left + right) / 2;
	dc(left, middle);
	dc(middle + 1, right);
	dc_merge(left, middle, right);
}

void dc_merge(int left, int middle, int right) {
	int id1 = left, id2 = middle + 1;
	int top = 0, d = 0;
	while(id1 <= middle && id2 <= right) {
		if(data[id1].y < data[id2].y) {
			tmp[top++] = data[id1++];
			d++;
		} else {
			tmp[top++] = data[id2++];
			tmp[top - 1].rank += d;
		}
	}
	while(id1 <= middle)
		tmp[top++] = data[id1++];
	while(id2 <= left){
		tmp[top++] = data[id2++];
		tmp[top - 1].rank += d;
	}
	for(int i = 0; i < top; i++)
		data[left++] = tmp[i];
}
