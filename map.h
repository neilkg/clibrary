#ifndef MAP_H
#define MAP_H


// made using a binary search tree
// O(log n) search, insertion, and removal
template <typename T>
class map {
public:
    
    map();
    
    bool empty();
    
    int size();
    
    V &operator[](K key);
    
    // insert returns whether inserted successfully
    // (if the key already exists in the table, do nothing and return false).
    bool insert(const K& key, const V& val);
    
    // erase returns the number of items remove (0 or 1)
    size_t erase(const K& key);
    
    // returns index or -1 if key not found
    int find_index(const K& key);
    
private:
    
};

#endif
