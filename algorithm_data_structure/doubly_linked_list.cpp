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
        void pushFront(int);
        void pushBack(int);
        void insertAfter(ListNode*, int);
        void insertAt(int, int);
        ListNode* popFront(void);
        ListNode* popBack(void);
        void deleteNode(ListNode*);
        void clear(void);

        // other operations
        void reverse(void);

    private:
        int _len;
        ListNode* _first;
        ListNode* _last;

        bool isContained(ListNode*);
};

LinkedList::LinkedList(void) {

    _len = 0;
    _first = NULL;
    _last = NULL;
}

LinkedList::~LinkedList(void) {

    printf("destruct linked list\n");
    clear();
}

// get i-th list node (pointer)
ListNode* LinkedList::getNode(int index) {

    if (index >= _len || index < 0) {

        return NULL;
    }

    ListNode* target = _first;

    for (int i = 0; i < index; i++) {

        target = target->next();
    }

    return target;
}

// return the first matched node
ListNode* LinkedList::searchNode(int data) {

    if (_len == 0) {

        return NULL;
    }

    int i = 0;
    ListNode* target = _first;

    for (int i = 0; i < _len; i++) {

        if (target->getData() == data) {

            return target;
        }

        target = target->next();
    }

    return NULL;
}

// get length of list
int LinkedList::getLength(void) {

    return _len;
}

void LinkedList::print(void) {

    if (_len <= 12) {

        int values[_len];

        ListNode* current = _first;

        for (int i = 0; i < _len; i++) {

            values[i] = current->getData();

            current = current->next();
        }

        printf("data: [ ");

        for (int i = 0; i < _len; i++) {

            printf("%d, ", values[i]);
        }

        printf("]\n");

    } else {

        int frontValues[6];
        int rearValues[6];

        ListNode* frontCurrent = _first;
        ListNode* rearCurrent = _last;
        
        for (int i = 0; i < _len; i++) {

            frontValues[i] = frontCurrent->getData();
            rearValues[5-i] = rearCurrent->getData();

            frontCurrent = frontCurrent->next();
            rearCurrent = rearCurrent->prev();
        }

        printf("data: [ ");

        for (int i = 0; i < 6; i++) {

            printf("%d, ", frontValues[i]);
        }

        printf("... , ");

        for (int i = 0; i < 6; i++) {

            printf("%d, ", rearValues[i]);
        }

        printf("]\n");
    }
}

// check if the node is contained in the list
bool LinkedList::isContained(ListNode* node) {

    ListNode* current = _first;
    for (int i = 0; i < _len; i++) {

        if (current == node) {

            return true;
            break;
        }

        current = current->next();
    }

    return false;
}

// create a new node and append to the list's head
void LinkedList::pushFront(int data) {

    // create node and set it as the head of list
    ListNode* newNode = new ListNode(NULL, _first, data);

    // let original head->prev points to newly created node
    _first->setPrev(newNode);

    // make _first point to newly created node
    _first = newNode;

    // if there's no node in the list previously, the new node is also the last node in list
    if (_len == 0) {

        _last = newNode;
    }

    // update list length
    _len += 1;
}


// create a new node and append to the list's end
void LinkedList::pushBack(int data) {

    ListNode* newNode = new ListNode(_last, NULL, data);

    _last->setNext(newNode);

    _last = newNode;

    if (_len == 0) {

        _first = newNode;
    }

    _len += 1;
}

// create a new node and append after a certain node in list
void LinkedList::insertAfter(ListNode* target, int data) {

    if (_len == 0 || target == NULL) {

        pushFront(data);

        return;
    }

    ListNode* current = _first;

    bool found = false;

    for (int i = 0; i < _len; i++) {

        if (current == target) {

            ListNode* newNode = new ListNode(current, current->next(), data);

            if (current->next() != NULL) {

                current->next()->setPrev(current);
            
            } else {

                _last = newNode;
            }

            current->setNext(newNode);

            _len += 1;

            found = true;
            break;
        }

        current = current->next();
    }

    if (!found) {
        
        printf("target not found \n");
    }
}

// create a new node and insert to a specitic position in list
void LinkedList::insertAt(int index, int data) {

    if (index >= _len) {

        printf("index out of range\n");
        return;
    }

    if (index == 0 && _len == 0) {

        pushFront(data);
    }

    // get original i-th node
    ListNode* ithNode = _first;
    for (int i = 0; i < index; i++) {

        ithNode = ithNode->next();
    }

    ListNode* ithPrevNode = ithNode->prev();

    ListNode* newNode = new ListNode(ithPrevNode, ithNode, data);

    if (ithPrevNode != NULL) {

        ithPrevNode->setNext(newNode);

    } else {

        _first = newNode;
    }

    ithNode->setPrev(newNode);

    _len += 1;
}

ListNode* LinkedList::popFront(void) {

    if (_len == 0) {

        return NULL;
    }

    if (_len == 1) {

        delete _first;

        _first = NULL;
        _last = NULL;

        _len -= 1;

    } else {

        ListNode* newFirst = _first->next();

        delete _first;

        _first = newFirst;

        _len -= 1;
    }
}

ListNode* LinkedList::popBack(void) {

    if (_len == 0) {

        return NULL;
    }

    if (_len == 1) {

        delete _last;

        _first = NULL;
        _last = NULL;

        _len -= 1;

    } else {

        ListNode* newLast = _last->prev();

        delete _last;

        _last = newLast;

        _len -= 1;
    }
}

void LinkedList::deleteNode(ListNode* target) {

    if (_len == 0) {

        return;
    }

    if (_len == 1) {

        delete _first;

        _first = NULL;
        _last = NULL;
        _len -= 1;

        return;
    }

    ListNode* current = _first;

    for (int i = 0; i < _len; i++) {

        if (current == target) {

            ListNode* prev = current->prev();
            ListNode* next = current->next();

            delete current;

            if (prev != NULL) {

                prev->setNext(next);

            } else {

                _first = next;
            }
            
            if (next != NULL) {

                next->setPrev(prev);

            } else {

                _last = prev;
            }
            
            _len -= 1;

            break;
        }
    }
}

// clear all nodes in linked list
void LinkedList::clear(void) {

    ListNode* next;
    ListNode* current = _first;

    while(_len > 0) {

        next = current->next();

        delete current;

        current = next;
        _len -= 1;
    }

    _first = NULL;
    _last = NULL;
}

// reverse list order
void LinkedList::reverse(void) {

    ListNode* current = _first;

    for (int i = 0; i < _len; i++) {

        ListNode* oldNext = current->next();

        current->setNext(current->prev());

        current->setPrev(oldNext);

        current = current->next();
    }

    ListNode* oldFirst = _first;

    _first = _last;
    _last = _first;
}

int main() {

    return 0;
}