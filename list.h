
template <typename T>
class list {
public:
    
    list();
    
    void push_back(T & val);
    
    void push_front(T & val);
    
    void pop_back();
    
    void pop_front();
    
    T& back();
    
    T& front();
    
    int size();
    
    bool empty();
    
    
private:
    
};
