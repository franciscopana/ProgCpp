#include <iostream>
using namespace std;
 
//! Complex number
struct complex {
  int real;  // Real part
  int img;   // Imaginary part
};
 
//! Print array of complex numbers.
void print(const complex z[], int n) {
  cout << "[ ";
  for (int i = 0; i < n; i++) {
    if (z[i].real == 0 && z[i].img == 0) 
      cout << 0;
    else {
      if (z[i].real != 0)
        cout << z[i].real;
      if (z[i].img > 0) 
        cout  << '+' << z[i].img << 'i';
      else if (z[i].img < 0) 
        cout  << z[i].img << 'i';
    }
    cout << ' ';
  }
  cout << "]\n";
}

complex sumc(complex c1, complex c2){
    complex c = {c1.real + c2.real, c1.img + c2.img};
    return c;
}

complex mulc(complex c1, complex c2){
    complex c = {c1.real * c2.real - c1.img * c2.img, c1.real * c2.img + c2.real * c1.img};
    return c;
}


void mandel(complex c, int n, complex z[]){
    z[0] = complex {0,0};
    for(int i = 1; i < n; i++){
        z[i] = sumc(mulc(z[i-1], z[i-1]), c);
    }
}

int main(){
    complex c = { 1, 1 };
    const int n = 3;
    complex z[n];
    mandel(c, n, z);
    print(z, n);
    return 0;
}