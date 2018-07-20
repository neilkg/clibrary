#ifndef MAP_H
#define MAP_H

#include "AVL.h"

// NEIL GOLLAPUDI

// made using a AVL tree
// O(log n) search, insertion, and removal
// Faster iteration than Unordered map
template <typename V, typename K>
class map {
public:
    
    map();
    
    bool empty() {
        return elts.empty;
    }
    
    int size() {
        return elts.size;
    }
    
    V &operator[](K key);
    
    // insert returns whether inserted successfully
    // (if the key already exists in the table, do nothing and return false).
    bool insert(const K& key, const V& val);
    
    // erase returns the number of items remove (0 or 1)
    size_t erase(const K& key);
    
private:
    AVL<V> elts;
    
};

#endif
