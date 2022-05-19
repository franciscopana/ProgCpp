// question 3

#include <iostream>
using namespace std;

//! Doubly-linked node containing an int value.
struct dlnode {
  int value;     // Value.
  dlnode* prev;  // Previous node.
  dlnode* next;  // Next node.
};

//! Builds a new node containing value v followed by next.
dlnode* build(int v, dlnode* next=nullptr) {
  dlnode* n = new dlnode { v , nullptr, next };
  if (next != nullptr) { next->prev = n; }
  return n;
}

//! Releases the memory allocated to n and successors.
void destroy(dlnode* n) {
  while (n != nullptr) {
    dlnode* aux = n -> next;
    delete n;
    n = aux;
  }
}

//! Prints 
void print(const dlnode* n) {
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

dlnode* insert(dlnode* dln, int k, int v){
  if(dln ==  nullptr){
    dlnode* nova = build(v, nullptr);
    nova->prev = nullptr;
    return nova;
  }
  if(k==0){
    dlnode* nova = build(v, dln);
    dln->prev = nova;
    return nova;
  }
  dlnode* atual = dln;
  dlnode* prox = dln->next;
  for(int i=1; i<=k; i++){
    if(i==k){
      dlnode* nova = build(v, prox);
      nova->prev = atual;
      atual->next = nova;
      if(prox!=nullptr){
        prox->prev = nova;
      }
      return dln;
    }
    else{
      atual = atual->next;
      prox = prox->next;
    }
  }

  return dln;
}
