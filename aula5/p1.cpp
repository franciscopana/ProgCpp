#include <iostream>
using namespace std;

int main(){
    char c;
    cin >> c;
    if ('0' <= c && c <= '9'){
        cout << "DIGIT" << endl;
        return 0;
    }
    if(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')){
        cout << "LETTER" << endl;
        return 0;
    }
    cout << "OTHER" <<  endl;
    return 0;
}