#include <map>
#include <list>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

string cat_keys(list<map<string, unsigned>> lst){
    unsigned max = UINT_MAX;
    int n = 0, i = 0;
    string result;
    for(map<string, unsigned> mzinho : lst){
        map<string, unsigned>::iterator it = mzinho.begin();
        while(it != mzinho.end()){
            if(it->second < max){
                n = i;
                max = it->second;
            }
            it++;
        }
        i++;
    }
    list<map<string, unsigned>>::iterator listIt = lst.begin();
    advance(listIt, n);
    map<string, unsigned> mzinho_min = *listIt;
    map<string, unsigned>::iterator mapIt = mzinho_min.begin();
    while(mapIt != mzinho_min.end()){
        result += mapIt->first;
        mapIt++;
    }
    return result;
}

int main(){
    return 0;
}