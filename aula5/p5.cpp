#include <iostream>
using namespace std;

//! Doubly-linked node containing an int value.
struct node {
  int value;     // Value.
  node* prev;  // Previous node.
  node* next;  // Next node.
};

//! Builds a new node containing value v followed by next.
node* build(int v, node* next=nullptr) {
  node* n = new node { v , nullptr, next };
  if (next != nullptr) { next->prev = n; }
  return n;
}

//! Releases the memory allocated to n and successors.
void destroy(node* n) {
  while (n != nullptr) {
    node* aux = n -> next;
    delete n;
    n = aux;
  }
}

//! Prints 
void print(const node* n) {
  while (n != nullptr) {
    cout << "(";
    if (n->prev == nullptr) cout << "\\<";
    else cout << n->prev->value << '<';
    cout << n->value << '<';
    if (n->next == nullptr) cout << "\\)";
    else cout << n->next->value << ')';
    n = n->next;
  }
  cout << '\n';
}

node* reverse(const node* n){
    if(n == nullptr) return nullptr;
    while(n->next != nullptr) 
        n = n->next;
    node* result = build(n->value, nullptr);
    node* first = result;
    while(n->prev != nullptr){
        n = n->prev;
        node* newnode = build(n->value, nullptr);
        newnode->prev = result;
        result->next = newnode;
        result = result->next;
    }
    return first;
}

int main(){
    node* a = build(1, build(2, build(3, nullptr)));
    node* b = reverse(a);
    print(b); 
    destroy(a); destroy(b);
    return 0;
}