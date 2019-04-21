#include <cstdio>
using namespace std;

class ListNode {

    public:
        ListNode(ListNode*, ListNode*, int);
        ~ListNode();
        ListNode* next(void);
        ListNode* prev(void);
        void setNext(ListNode*);
        void setPrev(ListNode*);
        int getData(void);
        void setData(int);

    private:
        ListNode* _next;
        ListNode* _prev;
        int _data;
};

ListNode::ListNode(ListNode* prev, ListNode* next, int data) {

    _prev = prev;
    _next = next;
    _data = data;
}

ListNode::~ListNode(void) {

    printf("destruct node(data: %d)\n", _data);
}

ListNode* ListNode::next(void) {

    return _next;
}

ListNode* ListNode::prev(void) {

    return _prev;
}

void ListNode::setPrev(ListNode* prev) {

    _prev = prev;
};

void ListNode::setNext(ListNode* next) {

    _next = next;
};

int ListNode::getData(void) {

    return _data;
}

void ListNode::setData(int data) {

    _data = data;
}

class LinkedList {

    public:
        LinkedList(void);
        ~LinkedList(void);

        // getting data
        ListNode* getNode(int);
        ListNode* searchNode(int);
        int getLength(void);
        void print(void);

        // node adding / removing
        void pushFront(ListNode*);
        void pushBack(ListNode*);
        ListNode* popFront(ListNode*);
        ListNode* popBack(ListNode*);
        void insertNode(ListNode*);
        void deleteNode(ListNode*);
        void clear(void);

        // other operations
        void reverse(void);
        void sort(void);

    private:
        int _len;
};

int main() {

    return 0;
}