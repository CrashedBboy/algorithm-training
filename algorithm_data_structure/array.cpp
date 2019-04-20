#include <iostream>
using namespace std;

const int kSize = 1024;

class Array {

    public:
        Array(int);
        ~Array();

        // basic operation
        int get(int);
        int length(void);
        void insert(int, int);
        void push(int);
        int pop(bool);
        void remove(int);

        // helper
        void sort(void);
        int min(void);
        int max(void);
    private:
        int* _data;
        int _len;
};

// constructor
Array::Array(int length = 100) {

    printf("create new array with length %d\n", length);

    _len = length;

    _data = new int[_len];
    
    for (int i = 0; i < _len; i++) {
        _data[i] = 0;
    }
}

// deconstructor
Array::~Array(void) {

    printf("deconstruct array\n");

    delete[] _data;
}

int Array::length(void) {

    return _len;
}

int main(void) {

    Array* arr = new Array(kSize);

    printf("arr length: %d\n", arr->length());

    delete arr;

    return 0;
}