#include <cstdio>
using namespace std;

class ListNode {

    public:
        ListNode(ListNode*, ListNode*);
        ListNode* next(void);
        ListNode* prev(void);
        void setNext(ListNode*);
        void setPrev(ListNode*);
        int getValue(void);
        int setValue(int);

    private:
        ListNode* _next;
        ListNode* _prev;
        int _data;
};

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
};

int main() {


    return 0;
}