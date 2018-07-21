#ifndef AVL_H
#define AVL_H

// NEIL GOLLAPUDI

template <typename T>
class AVL {
public:
    
    bool empty();
    
    int size();
    
private:
    struct Node {
        int val;
        Node *left;
        Node* right;
    };
    
    Node* top;
    
};


#endif
