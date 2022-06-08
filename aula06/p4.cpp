#include <string>
#include <vector>
using namespace std;

string longest_prefix(const vector<string>& v){
    string res = v[0];
    for(string e : v){
        string aux = "";
        int i = 0;
        while(e[i] == res[i]) aux += e[i++];
        res = aux;
    }
    return res;
}