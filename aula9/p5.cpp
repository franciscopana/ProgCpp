#include <iostream>
#include <iomanip>
using namespace std;
 
#include "Stack.h"

template <typename T>
Stack<T>::Stack(){
    size_ = 0;
    top_ = nullptr;
}

template <typename T>
Stack<T>::~Stack(){
    while(top_ != nullptr){
        size_--;
        node<T>* aux = top_->next;
        delete top_;
        top_ = aux;
    }
}

template <typename T>
bool Stack<T>::peek(T& v) const{
    if(size_ <= 0) return false;
    v = top_->value;
    return true;
}

template <typename T>
bool Stack<T>::pop(T& v){
    if(size_ <= 0) return false;
    v = top_->value;
    size_--;
    node<T>* aux = top_->next;
    delete top_;
    top_ = aux;
    return true;
}

template <typename T>
void Stack<T>::push(const T& v){
    top_ = new node<T>{v, top_};
    size_++;
}

template <typename T>
size_t Stack<T>::size() const{
    return size_;
}

int main(){
    Stack<string> s; string v;
    s.push("a"); s.push("b"); s.push("c");
    cout << s.size();
    while(s.pop(v)) cout << ' ' << v;
    cout << ' ' << s.size() << '\n';
    return 0;
}