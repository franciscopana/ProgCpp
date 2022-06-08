#include <iostream>

using namespace std;

//! Print array.
void print(int a[], int size) {
  cout << "[ ";
  for (int i = 0; i < size; i++)
    cout << a[i] << " ";
  cout << "]";
  cout << endl;
}

void remove_duplicates(int a[], int& size){
    int newsize = size;
    int p = 1;
    int n = 1;
    while(n < size){
        if (a[n] != a[n-1]){
            a[p] = a[n];
            n++; p++;
            continue;
        }
        n++;
        newsize--;
    }
    size = newsize;
}