#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

// NEIL GOLLAPDUI

// made using a singly linked list
// O(1) insertion and removal
template <typename T>
class queue {
public:

    bool empty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
    
    T &front() {
        return data.front();
    }
    
    void push(const T &val) {
        data.push_back(val);
    }
    
    void pop() {
        data.pop_front();
    }
    
private:
    list<T> data;
    
    
};

#endif
