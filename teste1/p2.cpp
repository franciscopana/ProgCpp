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
 
//! Determines whether 'number' is a prime number.
bool is_prime(int number) {
  if (number <= 1) return 0;
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) return false;
  }
  return true;
}

void keep_prime_numbers(int a[], int& size){
    int newsize = 0;
    int* newa = new int[size];
    int k = 0;
    for(int i = 0; i < size; i++){
        if(is_prime(a[i])){
            newa[k++] = a[i];
            newsize++;
        }
    }
    for(int i = 0; i < newsize; i++){
        a[i] = newa[i];
    }
    size = newsize;
    delete[] newa;
}

int main(){
    return 0;
}