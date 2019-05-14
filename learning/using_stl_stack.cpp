#include <stack>
#include <iostream>

using namespace std;

int main(void) {

    // declare stack instance
    stack<int> myStack;

    // whether stack is empty
    if (myStack.empty()) {
        printf("myStack is empty.\n");
    }

    // push element
    myStack.push(32);
    myStack.push(64);
    myStack.push(96);

    // pop element (pop() diesn't return any value)
    myStack.pop();

    // get size
    printf("myStack size: %d\n", myStack.size());

    // get top
    printf("myStack top: %d\n", myStack.top());

    return 0;
}