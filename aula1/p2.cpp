#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string result;
    while(n > 0){
        int last_digit = n%10;
        result = result + to_string(last_digit);
        n = n/10;
    }
    cout << stoi(result) << endl;
    return 0;
}

string alternative(int n){
    string str = to_string(n), result;
    for(int i = str.length(); i>0; i--){
        result = result + str[i-1];
    }
    cout << stoi(result) << endl;
}