#ifndef LIST_H
#define LIST_H

// NEIL GOLLAPUDI

// singly linked linked list
// O(n) search, custom removal
// O(1) removal, insertion
// singly linked list cannot pop_back() in O(1)
template <typename T>
class list {
public:
    
    list() : first(nullptr), last(nullptr), list_size(0) {}
    
    ~list() {
        clear();
    }
    
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
    
    void push_front(const T &val) {
        Node *temp = new Node;
        temp->val = val;
        if (first == nullptr) {
            first = temp;
            last = temp;
        }
        else {
            temp->next = first;
            first = temp;
        }
        ++list_size;
    }
    
    void push_back(const T &val) {
        Node *temp = new Node;
        temp->val = val;
        if (first == nullptr) {
            first = temp;
            last = temp;
        }
        else {
            last->next = temp;
            last = temp;
        }
        ++list_size;
    }

    void pop_front() {
        Node *temp = first;
        first = first->next;
        delete temp;
        --list_size;
    }
    
    // returns true if val is deleted in list
    bool remove(const T &val) {
        if (first->val == val) {
            pop_front();
            return true;
        }
        Node *temp = first;
        while (temp->next) {
            if (temp->next->val == val) {
                Node *to_delete = temp->next;
                temp->next = to_delete->next;
                delete to_delete;
                --list_size;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    // returns true if val is found in list
    bool find(const T &val) {
        Node *temp = first;
        while (temp) {
            if (temp->val == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // REQUIRES: list is not empty
    T& front() {
        return first->val;
    }
    
    T& back() {
        return last->val;
    }

    int size() {
        return list_size;
    }
    
    bool empty() {
        return first == nullptr;
    }
    
    // REQUIRES: Index is within the bounds of the scope
    T &operator[](int idx) {
        Node*temp = first;
        for (int i = 0; i < idx; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    
private:
    struct Node {
        T val;
        Node *next = nullptr;
    };
    
    Node *first;
    Node *last;
    int list_size;
    
};

#endif
