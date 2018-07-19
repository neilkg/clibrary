
// singly linked linked list
// O(n) search, custom removal
// O(1) removal, insertion
template <typename T>
class list {
public:
    
    list() : begin(nullptr), size(0) {}
    
    ~list() {
        while (!empty()) {
            pop_front();
        }
    }
    
    void push_front(T &val) {
        Node *temp = new Node;
        temp->val = val;
        temp->next = first;
        first = temp;
    }

    void pop_front() {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
    
    // returns true if val is deleted in list
    bool remove(T &val) {
        if (first->val = val) {
            pop_front();
            return true;
        }
        Node *temp = first;
        while (temp->next) {
            if (temp->next->val == val) {
                Node *to_delete = temp->next;
                temp->next = to_delete->next;
                delete to_delete;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    // returns true if val is found in list
    bool find(T &val) {
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

    int size() {
        return size;
    }
    
    bool empty() {
        return first == nullptr;
    }
    
    
private:
    Node *first;
    int size;
    
    struct Node {
        T val;
        Node *next = nullptr;
    }
    
};
