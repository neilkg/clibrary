#ifndef VECTOR_H
#define VECTOR_H

// NEIL GOLLAPDUI

template <typename T>
class vector {
public:
    // constructs an empty container with 0 elements
    vector() {
        data = new T[10];
        elts_capacity = 10;
        elts_size = 0;
    }
    
    // constructs a container size n with each elements being val
    vector(int n, T val) {
        data = new T[n];
        elts_capacity = n;
        elts_size = n;
        for (int i = 0; i < n; ++i) {
            data[i] = val;
        }
    }
    
    //range based constructor
    template <class Iterator>
    vector(Iterator begin, int size) {
        data = new T[10];
        elts_capacity = 10;
        elts_size = 0;
        for (int i = 0; i < size; ++i) {
            push_back(*begin);
            ++begin;
        }
    }
    
    
    //destructor
    ~vector() {
        delete data;
    }
    
    // copy constructor
    vector(const vector<T> &other) {
        elts_size = other.elts_size;
        elts_capacity = other.elts_capacity;
        data = new T[elts_capacity];
        for (int i = 0; i < elts_size; ++i) {
            data[i] = other.data[i];
        }
    }
    
    // assignment operator
    vector & operator= (const vector<T> &rhs) {
        if (&rhs != this) {
            elts_size = rhs.elts_size;
            elts_capacity = rhs.elts_capacity;
            delete data;
            T* temp = new T[elts_capacity];
            data = temp;
            for (int i = 0; i < elts_size; ++i) {
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }
    
    bool empty() {
        return elts_size == 0;
    }
   
    int size() {
        return elts_size;
    }
    
    T &front() {
        return data[0];
    }

    T &back() {
        return data[elts_size - 1];
    }
    
    // amortized O(n)
    void push_front(const T &val) {
        if (elts_size == elts_capacity) {
            grow(elts_capacity * 2);
        }
        for (int i = elts_size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = val;
        ++elts_size;
    }
    
    // amortized O(1)
    void push_back(const T &val) {
        if (elts_size == elts_capacity) {
            grow(elts_capacity * 2);
        }
        data[elts_size] = val;
        ++elts_size;
    }
    
    // O(n)
    void pop_front() {
        for (int i = 0; i < elts_size - 1; ++i) {
            data[i] = data[i + 1];
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
        delete data;
        data = temp;
    }
    
    // resizes vector of size n with val filling in the rest
    void resize(const int n, const T &val) {
        T * temp = new T[n];
        if (n > elts_size) {
            int stop = 0;
            for (int i = 0; i < elts_size; ++i) {
                temp[i] = data[i];
                ++stop;
            }
            for (int i = stop; i < n; ++i) {
                temp[i] = val;
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                temp[i] = data[i];
            }
        }
        elts_capacity = n;
        elts_size = n;
        delete data;
        data = temp;
    }
    
    // REQUIRES: Index is withing the bounds of the scope
    T &operator[](int idx) {
        return data[idx];
    }
    
    T* begin() {
        return data;
    }
    
private:
    T *data;
    int elts_capacity;
    int elts_size;
    
    // creates new dyanamic array of size n and copies over previous elements
    void grow(int n) {
        elts_capacity = n;
        T *temp = new T[elts_capacity];
        for (int i = 0; i < elts_size; ++i) {
            temp[i] = data[i];
        }
        delete data;
        data = temp;
    }
    
};

#endif
