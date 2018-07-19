#include <vector.h>

template <typename T>
class stack {
public:
    
    stack();
    
    bool empty() {
        return elts.size() == 0;
    }
    
    int size() {
        return elts.size();
    }
    
    T &top() {
        return elts[elts.size() - 1];
    }
    
    void push(T &val) {
        elts.push_back(val);
    }
    
    void pop() {
        elts.pop_back();
    }
    
    
private:
    vector<T> elts;
    
};
