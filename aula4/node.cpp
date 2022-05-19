
#include <iostream>
using namespace std;

//! Singly-linked node containing an int value.
struct node {
  int value;
  node* next;
};

//! Builds a new node with value x followed by n.
node* build(int x, node* n) {
  return new node { x , n };
}

//! Releases the memory allocated to n and successors.
void destroy(node* n) {
  while (n != nullptr) {
    node* aux = n->next;
    delete n;
    n = aux;
  }
}

//! prints Values in the node pointed by n and successors.
void print(const node* n) {
  if (n == nullptr){
    cout << "[]\n";
  } else {
    cout << '[' << n->value;
    while (n->next != nullptr) {
      n = n->next;
      cout << ',' << n->value;
    }
    cout << "]\n";
  }
}

node* remove(int x, node* n){
  if(n == nullptr){
    return nullptr;
  }

  node* prev = n;
  node* cur = n->next;

  if(prev->value == x){
    node* res = n->next;
    delete(n);
    return res;
  }

  while(cur != nullptr){
    if(cur->value == x){
      prev->next = cur->next;
      delete(cur);
      return n;
    }
    else{
      prev = prev->next;
      cur = cur->next;
    }
  }
  return n;
}

node* merge_sorted(node* a, node* b){
  if(a == nullptr && b == nullptr)  return nullptr;
  node* c = build(0,nullptr);
  node* first = c;
  while(a!=nullptr && b!=nullptr){
    if(a->value < b->value){
      c->next = build(a->value, nullptr);
      a = a->next;
    }
    else{
      c->next = build(b->value, nullptr);
      b = b->next;
    }
    c = c->next;
  }
  while(a!=nullptr){
      c->next = build(a->value, nullptr);
      a = a->next;
      c = c->next;
  }
  while(b!=nullptr){
      c->next = build(b->value, nullptr);
      b = b->next;
      c = c->next;
  }
  node* final = first->next;
  delete first;
  return final;
}
