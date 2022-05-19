#include <string>
using namespace std;

void update_alpha(int index, int* alpha){
    alpha[index]++;
}

bool pangram(const string& s, string& m){

    int alpha[26] = {0};

    for(size_t i = 0; i < s.length(); i++){
        if ('a' <= s[i] && s[i] <= 'z'){
            update_alpha(s[i] - 'a', alpha);
        }
        if ('A' <= s[i] && s[i] <= 'Z'){
            update_alpha(s[i] - 'A', alpha);
        }
    }
    for(int i = 0; i < 26; i++){
        if(alpha[i] == 0)
            m += 'a' + i;
    }
    return m == "";
}
