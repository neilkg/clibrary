#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <functional>
#include "vector.h"
#include "AVL.h"

// NEIL GOLLAPUDI

// HASHTABLE
// O(1) amortized lookup, insertion, deletion
// AVL tree collision resolution method;
// for collision, O(log n) search, insertion, and deletion

template <typename K, typename V, typename Hash = std::hash<K>>
class unordered_map {
public:
    
    unordered_map();
    
    bool empty();
    
    int size();
    
    // if doesnt exist, makes an entry with that key
    V &operator[](K key);
    
    // insert returns if successfully inserted
    // (if key exists in the table, do nothing and return false).
    bool insert(const K& key, const V& val);
    
    // erase returns true if successfully deleted
    // (if key does not exist in table, do nothing and return false).
    bool erase(const K& key);
    
    // returns index or -1 if key not found
    int find_index(const K& key);
    
    
private:
    vector<AVL<V>> elts;

};

#endif
