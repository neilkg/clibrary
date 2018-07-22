#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <functional>
#include <utility>
#include "vector.h"
#include "algorithm.h"

// NEIL GOLLAPDUI


// Array Based Binary Priority Queue Implementation
// O(log n) insertion and removal
// O(n) build heap
// Contains null data at position 0
// parent located at (n / 2)
// left child located at (2 * n)
// right child located at (left child + 1)
template <typename T, class Compare = std::less<T>>
class priority_queue {
public:
    
    priority_queue(Compare comp = Compare()) {
        comp_functor = comp;
        data.push_back(T());
    }
    
    template <class Iterator>
    priority_queue(Iterator first, Iterator last, Compare comp = Compare()) {
        comp_functor = comp;
        data.push_back(T());
        for (Iterator i = first; i != last; ++i) {
            data.push_back(*i);
        }
        update_priorities();
    }
    
    const T &top() {
        return data[1];
    }
    
    bool empty() {
        return data.size() == 1;
    }
    
    int size() {
        return data.size() - 1;
    }
    
    // O(log n)
    void push(const T &val) {
        data.push_back(val);
        fix_up(size());
    }
    
    // O(log n)
    void pop() {
        swap(data[1], data[size()]);
        data.pop_back();
        fix_down(1);
    }
    
    // O(n)
    void update_priorities() {
        for (int i = size(); i >= 1; --i) {
            if (i * 2 <= size()) {
                fix_down(i);
            }
        }
    }
    
private:
    vector<T> data;
    Compare comp_functor;
    
    // O(log n)
    void fix_down(int n) {
        int parent = n;
        while (parent * 2 <= size()) {
            int child = parent * 2;
            if (child < size() && comp_functor(data[child], data[child + 1])) {
                ++child;
            }
            if (!comp_functor(data[parent], data[child])) {
                return;
            }
            swap(data[parent], data[child]);
            parent = child;
        }
    }
    
    // O(log n)
    void fix_up(int n) {
        while (n > 1 && comp_functor(data[n / 2], data[n])) {
            swap(data[n / 2], data[n]);
            n = n / 2;
        }
    }

};

#endif
