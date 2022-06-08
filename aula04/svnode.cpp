// question 5

#include <iostream>

using namespace std;

// Sparse vector node.
struct svnode {
  int position;  // Position.
  int value;     // Value (different from 0)
  svnode* next;  // Successor node (if non-null, position < next->position)
};

//! Build a new sparse vector node.
svnode* build(int position, int value, svnode* svn) {
  if (svn == nullptr || position < svn->position) {
    svn = new svnode { position, value, svn };
  } else {
    svn->next = build(position, value, svn->next);
  }
  return svn;
}

//! Destroy a sparse vector node and its successors.
void destroy(svnode* svn) {
  while (svn != nullptr) {
    svnode* aux = svn->next;
    delete svn;
    svn = aux;
  }
}

//! Print the contents (position-value pairs).
void print(const svnode* svn) {
  cout << "[";
  while (svn != nullptr) {
    cout << ' ' << svn->position 
         << ">" << svn->value;
    svn = svn->next;
  }
  cout << " ]";
}

svnode* sum(const svnode* a, const svnode* b){
  if(a == nullptr && b == nullptr) return nullptr;
  svnode* c = build(0, 0, nullptr);
  svnode* first = c;
  while(a != nullptr && b != nullptr){
    if(a->position == b->position){
      int val = a->value + b->value;
      if(val != 0){
        c->next = build(a->position, val, nullptr);
        c = c->next;
      }
      a = a->next;
      b = b->next;
    }
    else{
      svnode* d = (a->position < b->position) ? &a : &b;
      c->next = build(d->position, d->value, nullptr);
      c = c->next;
      d = d->next;
    }
  }
  while(b!=nullptr){
    c->next = build(b->position, b->value, nullptr);
    c = c->next;
    b = b->next;
  }
  while(a!=nullptr){
    c->next = build(a->position, a->value, nullptr);
    c = c->next;
    a = a->next;
  }
  svnode* aux = first->next;
  delete first;
  return aux;
}
