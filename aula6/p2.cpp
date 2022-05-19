#include <string>
#include <vector>
#include <iostream>
using namespace std;

//! Print vector of strings.
void print(const vector<string>& v) {
    cout << "[ ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << '\"' << v[i] << "\" ";
    }
    cout << "]\n";
}

void split(const string& s, vector<string>& v){
    size_t pos = s.find(" ", 0), last = 0;
    while(pos != string::npos){
        string new_str = s.substr(last, pos - last);
        if(new_str != "")
            v.push_back(new_str);
        last = pos+1;
        pos = s.find(" ",last);
    }
    string new_str = s.substr(last, s.length()-last);
    if(new_str != "")
        v.push_back(new_str);
}
