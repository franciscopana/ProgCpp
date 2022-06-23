#include <map>
#include <list>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

string smallest_sum_key(map<string, list<int>> m){
    string result;
    int min = INT_MAX;
    for(auto it = m.begin(); it != m.end(); it++){
        list<int> l = it->second;
        int sum = 0;
        for(auto itl = l.begin(); itl !=l.end(); itl++){
            sum += *itl;
        }
        if(sum < min){
            min = sum;
            result = it->first;
        }
    }
    return result;
}

int main(){
    return 0;
}