#include <iostream>
using namespace std;

int main() {
    int n;
    //cout << "Insira um número: "; 
    cin >> n;
    string result;
    for(int i = 1; i <= n; i++){
        if(i%3 == 0 && i%5 == 0) continue;
        if(i%3 == 0) {
            result = result + "Fizz "; 
            continue;
        }
        if(i%5 == 0) {
            result = result + "Buzz "; 
            continue;
        }
        result = result + to_string(i) + " ";
    }
    cout << result << endl;
    return 0;
}