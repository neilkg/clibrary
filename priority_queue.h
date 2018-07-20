#ifndef PRIOROTY_QUEUE_H
#define PRIORITY_QUEUE_H

// NEIL GOLLAPDUI

template <typename T>
class priority_queue {
public:
    priority_queue();
    
    T top();
    
    void pop();
    
    void push(T & val);
    
    bool empty();
    
    int size();
    
private:

};

#endif
