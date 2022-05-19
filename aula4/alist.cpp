// question 1

#include <iostream>
#include <cstdarg>
using namespace std;

//! Array list.
struct alist {
  int size;       // Number of elements.
  int* elements;  // List elements.
};

//! Build an empty list.
alist* empty() {
  return new alist { 0, nullptr };
}

//! Build array list.
alist* build(int n, int v[]) {
  alist* al = new alist;
  al->size = n;
  if (n == 0) {
    al->elements = nullptr;
  } else {
    al->elements = new int[n];
    for (int i = 0; i < n; i++) {
      al->elements[i] = v[i];
    }
  }
  return al;
}

//! Destroy array list
void destroy(const alist* al) {
  delete [] al->elements;
  delete al;
}

void print(const alist* al) {
  cout << '[';
  for (int i = 0; i < al->size; i++) { 
    cout << ' ' << al->elements[i];
  }
  cout << " ]\n";
}

//! Append function (declaration only, must be implemented).
void append(alist* a, const alist* b){
  int newsize = a->size + b->size;
  int* vect = new int [newsize];
  for(int i = 0; i < a->size; i++){
    vect[i] = a->elements[i];
  }
  for (int i = 0; i < b->size; i++)
  {
    vect[i+a->size] = b->elements[i];
  }
  delete[] a->elements;
  a->elements = vect;
  a->size = newsize;
}
