#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    // declare and assign(assign 10 elements which has value 25)
    vector<int> myVector(10, 25);

    // get size of vector
    printf("myVector size: %d\n", myVector.size());

    // using iterator to iterate whole vector and print
    vector<int>::iterator it;

    for (it = myVector.begin(); it != myVector.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    // mass assignment
    myVector.assign(10, 99);

    // using at() to get specific element value
    for (int i = 0; i < myVector.size(); i++) {
        printf("%d ", myVector.at(i));
    }
    printf("\n");

    // clear vector
    myVector.clear();
    printf("myVector size: %d\n", myVector.size());

    // or, use erase() to delete all elements
    myVector.assign(1000000, 25);
    myVector.erase(myVector.begin(), myVector.end());
    printf("myVector size: %d\n", myVector.size());

    // push element to vector's back
    myVector.clear();
    myVector.push_back(32);
    myVector.push_back(64);
    myVector.push_back(96);

    for (it = myVector.begin(); it != myVector.end(); it++) { printf("%d ", *it); }
    printf("\n");

    // pop element (pop_back() doesn't return popped element)
    myVector.pop_back();

    for (it = myVector.begin(); it != myVector.end(); it++) { printf("%d ", *it); }
    printf("\n");

    // get vector first value
    printf("first value of myVector: %d\n", myVector.front());

    // get vector last value
    printf("last value of myVector: %d\n", myVector.back());
    
    // assign specific element value
    myVector.assign(10, 10);
    myVector.at(4) = 20;

    for (it = myVector.begin(); it != myVector.end(); it++) { printf("%d ", *it); }
    printf("\n");

    // delete specific element
    myVector.assign(10, 10);

    myVector.at(4) = 99;

    it = myVector.begin();
    myVector.erase(it + 4); // delete myVector[4]

    for (it = myVector.begin(); it != myVector.end(); it++) { printf("%d ", *it); }
    printf("\n");

    return 0;
}