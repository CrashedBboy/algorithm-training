#include <iostream>
#include <exception>
using namespace std;

const int kSize = 65536;

class Array {

    public:
        Array(int);
        ~Array();

        // basic operation
        int get(int);
        void set(int, int);
        int length(void);
        void insert(int, int);
        void push(int);
        int pop(bool);
        void remove(int);

        // helper
        void sort(void);
        void print(void);
        int min(void);
        int max(void);
    private:
        int* _data;
        int _len;
        void merge(int, int, int, int);
};

// constructor
Array::Array(int length = 512) {

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

int Array::get(int index) {

    if (index >= _len || index < 0) {

        throw std::out_of_range("invalid index");
    }

    return _data[index];
}

void Array::set(int index, int value) {

    if (index >= _len || index < 0) {

        throw std::out_of_range("invalid index");
    }

    _data[index] = value;
}

void Array::insert(int index, int value) {

    if (index > _len || index < 0) {

        throw std::out_of_range("invalid index");
    }
    
    int* new_data = new int[_len+1];

    for (int i = 0; i < index; i++) {
        new_data[i] = _data[i];
    }

    new_data[index] = value;

    if (index < _len) {
        
        for (int i = index; i < _len; i++) {
            new_data[i+1] = _data[i];
        }
    }

    _len += 1;

    delete _data;
    _data = new_data;
}

void Array::push(int value) {

    int* new_data = new int[_len+1];

    for (int i = 0; i < _len; i++) {
        new_data[i] = _data[i];
    }

    new_data[_len] = value;

    _len += 1;

    delete _data;
    _data = new_data;
}

int Array::pop(bool rear = true) {

    int item, new_start_index, new_end_index;

    if (rear) {
        item = _data[_len-1];
        new_start_index = 0;
        new_end_index = _len - 2;
    } else {
        item = _data[0];
        new_start_index = 1;
        new_end_index = _len - 1;
    }

    int* new_data = new int[_len-1];

    for (int i = new_start_index, j = 0; i <= new_end_index; i++, j++) {
        new_data[j] = _data[i];
    }

    _len -= 1;

    delete _data;
    _data = new_data;

    return item;
}

void Array::remove(int index) {

    if (index >= _len || index < 0) {

        throw std::out_of_range("invalid index");
    }

    int* new_data = new int[_len-1];

    for (int i = 0; i < index; i++) {
        new_data[i] = _data[i];
    }

    for (int i = index+1; i < _len; i++) {
        new_data[i-1] = _data[i];
    }

    _len -= 1;

    delete _data;
    _data = new_data;
}

// sort by using merge sort
void Array::sort() {

    if (_len > 1) {
        int mid = _len/2;
        merge(0, mid, mid+1, _len-1);
    }
}

void Array::merge(int start_1, int end_1, int start_2, int end_2) {

    // check if list1 length is > 2, if so , divide (and merge)
    if ((end_1 - start_1) > 0) {
        int mid = (start_1 + end_1) / 2;
        merge(start_1, mid, mid+1, end_1);
    }

    // check if list2 length is > 2, if so , divide (and merge)
    if ((end_2 - start_2) > 0) {
        int mid = (start_2 + end_2) / 2;
        merge(start_2, mid, mid+1, end_2);
    }

    // create new array to store merged array (temporarily)
    int temp[end_2 - start_1 + 1];

    // indicator of next item to be merged
    int p1 = start_1, p2 = start_2, pt = 0;

    while(!((p1 > end_1) && (p2 > end_2))) {

        // list 1 has no item to merge, list 2 still has items to merge
        if ((p1 > end_1)) {
            
            for (int i = p2; i <= end_2; i++) {

                temp[pt] = _data[i];
                pt += 1;
            }
            p2 = end_2 + 1;
            break;
        }

        // list 2 has no item to merge, list 1 still has items to merge
        if ((p2 > end_2)) {

            for (int i = p1; i <= end_1; i++) {

                temp[pt] = _data[i];
                pt += 1;
            }
            p1 = end_1 + 1;
            break;
        }

        if (_data[p1] <= _data[p2]) {

            temp[pt] = _data[p1];
            p1 += 1;
            pt += 1;

        } else {

            temp[pt] = _data[p2];
            p2 += 1;
            pt += 1;
        }
    }

    // restore merged list to original array
    for (int i = start_1, j = 0; i <= end_2; i++, j++) {

        _data[i] = temp[j];
    } 
}

int Array::min(void) {

    int min = _data[0];

    for (int i = 1; i < _len; i++) {
        
        if (_data[i] < min) {
            min = _data[i];
        }
    }

    return min;
}

int Array::max(void) {

    int max = _data[0];

    for (int i = 1; i < _len; i++) {
        
        if (_data[i] > max) {
            max = _data[i];
        }
    }

    return max;
}

void Array::print(void) {

    if (_len > 12) {

        for (int i = 0; i < 6; i++) {
            printf("%d ", _data[i]);
        }

        printf(". . . . . ");

        for (int i = (_len-6); i < _len; i++) {
            printf("%d ", _data[i]);
        }

    } else {

        for (int i = 0; i < _len; i++) {
            printf("%d ", _data[i]);
        }
    }

    printf("\n");
}

int main(void) {

    Array* arr = new Array(kSize);

    int action, parameter_1, parameter_2;

    while (true) {

        printf("select one action: "
            "1) get item value, "
            "2) set item value, "
            "3) get array length, "
            "4) insert an item, "
            "5) push an item, "
            "6) remove an item, "
            "7) pop an item, "
            "8) sort, "
            "9) get min value, "
            "10) get max value, "
            "11) print array, "
            "other) exit \n");

        printf("action: ");
        scanf("%d", &action);

        if (action == 1) {

            printf("item index: ");
            scanf("%d", &parameter_1);

            printf("arr[%d]: %d \n", parameter_1, arr->get(parameter_1));

        } else if (action == 2) {
            
            printf("item index: ");
            scanf("%d", &parameter_1);

            printf("item value: ");
            scanf("%d", &parameter_2);

            arr->set(parameter_1, parameter_2);

        } else if (action == 3) {

            printf("arr length: %d \n", arr->length());

        } else if (action == 4) {

            printf("item index: ");
            scanf("%d", &parameter_1);

            printf("item value: ");
            scanf("%d", &parameter_2);

            arr->insert(parameter_1, parameter_2);

        } else if (action == 5) {

            printf("item value: ");
            scanf("%d", &parameter_1);

            arr->push(parameter_1);

        } else if (action == 6) {

            printf("item index: ");
            scanf("%d", &parameter_1);

            arr->remove(parameter_1);

        } else if (action == 7) {

            printf("rear? (1 or 0): ");
            scanf("%d", &parameter_1);

            printf("popped element: %d\n", arr->pop(parameter_1));

        } else if (action == 8) {
            
            arr->sort();

        } else if (action == 9) {

            printf("min value: %d \n", arr->min());

        } else if (action == 10) {

            printf("max value: %d \n", arr->max());

        } else if (action == 11) {

            arr->print();

        } else {

            break;
        }
    }

    delete arr;

    return 0;
}