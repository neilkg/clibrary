#ifndef STACK_H
#define STACK_H

#include "vector.h"

// NEIL GOLLAPUDI

// made using a vector
// O(1) insertion and removal
template <typename T>
class stack {
public:
    
    bool empty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
    
    T &top() {
        return data.back();
    }
    
    void push(const T &val) {
        data.push_back(val);
    }
    
    void pop() {
        data.pop_back();
    }
    
    
private:
    vector<T> data;
    
};

#endif
