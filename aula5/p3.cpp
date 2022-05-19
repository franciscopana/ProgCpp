#include <iostream>

using namespace std;

bool anagrams(const char a[], const char b[], int& n){
    int aa[26] = {0};
    int bb[26] = {0};
    int i = 0;
    while(a[i] != '\0'){
        char c = a[i];
        if ('a' <= c && c <= 'z'){
            int index = c-'a';
            aa[index]++;
        }
        if ('A' <= c && c <= 'Z'){
            int index = c-'A';
            aa[index]++;
        }
        i++;
    }
    i = 0;
    while(b[i] != '\0'){
        char c = b[i];
        if ('a' <= c && c <= 'z'){
            int index = c-'a';
            bb[index]++;
        }
        if ('A' <= c && c <= 'Z'){
            int index = c-'A';
            bb[index]++;
        }
        i++;
    }
    n = 0;
    for (int i=0; i<26; i++){
        int k = aa[i] - bb[i];
        if(k != 0){
            n += (k > 0) ? k : -k;
        }
    }
    return (n == 0) ? true : false;
}

int main(){
    char a[] = "Z Plus Plus after Python";
    char b[] = "zYTHON after p plus plus";
    int n = -1;
    bool r = anagrams(a, b, n);
    cout << '\"' << a << '\"' << ' '
        << '\"' << b << '\"' << ' '
        << boolalpha << r << ' ' << n << '\n';
    return 0;
}