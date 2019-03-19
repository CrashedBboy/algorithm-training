#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool match(char left, char right) {
	return (left == '(' && right == ')') || (left == '[' && right == ']');
}

int main(void) {
	int round;
	char input[128];
	scanf("%d", &round);
	getc(stdin);
	for (int i = 0; i < round; i++)	{
		vector<char> stack;
		gets(input);
		for (int j = 0; input[j] != '\0'; j++) {
			if (!stack.empty() && match(stack.back(), input[j]))
				stack.pop_back();
			else
				stack.push_back(input[j]);
		}
		if (stack.empty())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
