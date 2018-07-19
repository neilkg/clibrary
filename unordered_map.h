#include <functional>
#include "vector.h"


// sorted vector collision resolution method;
template <typename K, typename V, typename Hash = std::hash<K>>
class unordered_map {
public:
    
    unordered_map();
    
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
    vector<vector<T>> elts;

};
