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
    
    
private:
    vector<vector<T>> elts;
    
    
    
};
