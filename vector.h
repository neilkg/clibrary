#ifndef VECTOR_H
#define VECTOR_H


template <typename T>
class vector {
public:
    // constructs an empty container with 0 elements
    vector() {
        elts = new T[10];
        elts_capacity = 10;
        elts_size = 0;
    }
    
    // constructs a container size n with each elements being val
    vector(int n, T val) {
        elts = new T[n];
        elts_capacity = n;
        elts_size = n;
        for (int i = 0; i < n; ++i) {
            elts[i] = val;
        }
    }
    
    //range based constructor
    template <class Iterator>
    vector(Iterator begin, int size) {
        elts = new T[10];
        elts_capacity = 10;
        elts_size = 0;
        for (int i = 0; i < size; ++i) {
            push_back(*begin);
            ++begin;
        }
    }
    
    
    //destructor
    ~vector() {
        delete elts;
    }
    
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
    
    T &front() {
        return elts[0];
    }

    T &back() {
        return elts[elts_size - 1];
    }
    
    // amortized O(n)
    void push_front(const T &val) {
        if (elts_size == elts_capacity) {
            grow(elts_capacity * 2);
        }
        for (int i = elts_size; i > 0; --i) {
            elts[i] = elts[i - 1];
        }
        elts[0] = val;
        ++elts_size;
    }
    
    // amortized O(1)
    void push_back(const T &val) {
        if (elts_size == elts_capacity) {
            grow(elts_capacity * 2);
        }
        elts[elts_size] = val;
        ++elts_size;
    }
    
    // O(n)
    void pop_front() {
        for (int i = 0; i < elts_size - 1; ++i) {
            elts[i] = elts[i + 1];
        }
        --elts_size;
    }
    
    // O(1)
    void pop_back() {
        --elts_size;
    }
    
    // reserves memory for vector of size n
    // invalidates all previous elements
    void reserve(int n) {
        T* temp = new T[n];
        elts_capacity = n;
        delete elts;
        elts = temp;
    }
    
    // resizes vector of size n with val filling in the rest
    void resize(const int n, const T &val) {
        T * temp = new T[n];
        if (n > elts_size) {
            int stop = 0;
            for (int i = 0; i < elts_size; ++i) {
                temp[i] = elts[i];
                ++stop;
            }
            for (int i = stop; i < n; ++i) {
                temp[i] = val;
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                temp[i] = elts[i];
            }
        }
        elts_capacity = n;
        elts_size = n;
        delete elts;
        elts = temp;
    }
    
    // REQUIRES: Index is withing the bounds of the scope
    T &operator[](int idx) {
        return elts[idx];
    }
    
    T* begin() {
        return elts;
    }
    
private:
    T *elts;
    int elts_capacity;
    int elts_size;
    
    // creates new dyanamic array of size n and copies over previous elements
    void grow(int n) {
        elts_capacity = n;
        T *temp = new T[elts_capacity];
        for (int i = 0; i < elts_size; ++i) {
            temp[i] = elts[i];
        }
        delete elts;
        elts = temp;
    }
    
};

#endif
