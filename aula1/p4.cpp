#include <iostream>
#include <algorithm>

using namespace std;

string toBinary(int n)
{
    string r;
    while(n!=0){
        r = (n%2==0 ? "0":"1") + r;
        n/=2;
    }
    return r;
}

bool is_prime(int n){
    if(n<2){
        return false;
    }
    for(int i = 2; i < n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool is_pernicious(int n){
    string binary = toBinary(n);
    int occurences = count(binary.begin(), binary.end(), '1');
    return is_prime(occurences);
}

int main() {
    int a, b;
    cin >> a >> b;
    for(int i=a; i<=b; i++){
        if(is_prime(i) && is_pernicious(i)){
            cout << i << endl; 
        }
    }
    return 0;
}