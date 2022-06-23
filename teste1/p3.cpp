#include <iostream>
using namespace std;

bool heterogram(const char s[], char r[]){
    int alpha[26] = {0};
    int i = 0;
    while(s[i] != '\0'){
        char c = s[i];
        if('a' <= c && c <= 'z'){
            int index = c - 'a';
            alpha[index]++;
        }
        else if('A' <= c && c <= 'Z'){
            int index = c - 'A';
            alpha[index]++;
        }
        i++;
    }
    bool result = true;
    int k = 0;
    for(int i = 0; i < 26; i++){
        if(alpha[i] > 1){
            r[k++] = 'a' + i;
            result = false;
        }
    }
    if(result){
        for(int i = 0; i<27; i++){
            r[i] = 0;
        }
    }
    return result;
}

int main(){
    return 0;
}