#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <utility>
#include "vector.h"

// NEIL GOLLAPUDI

template <typename T>
void swap(T& one, T& two) {
    T temp = std::move(one);
    one = std::move(two);
    two = std::move(temp);
}

// must be a forward iterator
template <class Iterator, class T, class Compare>
Iterator lower_bound(Iterator first, Iterator last, const T& val, Compare comp) {
    int count;
    int step;
    count = int(std::distance(first, last));
    
    while (count > 0) {
        Iterator it = first;
        step = count / 2;
        std::advance(it, step);
        if (comp(*it, val)) {
            first = ++it;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return first;
}

// must be a forward iterator
template <class Iterator, class T, class Compare>
Iterator uppper_bound(Iterator first, Iterator last, const T& val, Compare comp) {
    int count;
    int step;
    count = int(std::distance(first,last));
    
    while (count > 0) {
        Iterator it = first;
        step=count / 2;
        std::advance(it,step);
        if (!comp(val, *it)) {
            first = ++it;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return first;
}



template <class Iterator>
void insertion_sort(Iterator begin, Iterator end);

template <class Iterator>
void sort(Iterator begin, Iterator end);

template <class Iterator, class Compare>
void insertion_sort(Iterator begin, Iterator end, Compare comp);


template <class Iterator, class Compare>
void sort(Iterator begin, Iterator end, Compare comp);

#endif
