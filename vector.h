
template <typename T>
class vector {
public:
    // constructs an empty container with 0 elements
    vector();
    
    // constructs a container size n with each elements being val
    vector(int n, T val);
    
    //range based constructor
    template <class Iterator>
    vector(Iterator begin, Iterator end);
    
    
    //destructor
    ~vector();
    
    // copy constructor
    vector(const vector<T> &other);
    
    // assignment operator
    vector & operator= (const vector<T> &rhs);
    
    bool empty() {
        return elts_size == 0;
    }
   
    int size() {
        return elts_size;
    }
    
    T &front();

    T &back();
    
    // amortized O(n)
    void push_front(const T &val);
    
    // amortized O(1)
    void push_back(const T &val);
    
    // O(n)
    void pop_front();
    
    // O(1)
    void pop_back();
    
    // reserves memory for vector of size n
    // invalidates all previous elements
    void reserve(int n);
    
    // resizes vector of size n with val filling in the rest
    void resize(int n, const T &val);
    
    // REQUIRES: Index is withing the bounds of the scope
    T &operator[](int idx);
    
private:
    T *elts;
    int elts_capacity;
    int elts_size;
    
    // creates new dyanamic array of size n and copies over previous elements
    void grow(int n);
    
};
