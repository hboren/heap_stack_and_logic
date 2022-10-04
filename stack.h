#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};
template <typename T>
Stack<T>::Stack(){

}


//return true if stack is empty
template <typename T>
bool Stack<T>::empty() const{
    //implement   
    return this->std::vector<T>::empty();
}

//return the current size of the stack
template <typename T>
size_t Stack<T>::size() const{
    return this->std::vector<T>::size();
}

//push given item to top of the stack
template <typename T>
void Stack<T>::push(const T& item){
    this->push_back(item);
}

//pop the top item from the stack
template <typename T>
void Stack<T>::pop(){
    if(Stack::empty()){
        throw std::underflow_error("Tried to call pop on empty stack");
    }
    this->pop_back();
}

//return the top item from the stack
template <typename T>
const T& Stack<T>::top() const{
    //implement
    if(Stack::empty()){
        throw std::underflow_error("Tried to call top on empty stack");
    }    
    return this->back();
}

template<typename T>
Stack<T>::~Stack() {

}

#endif