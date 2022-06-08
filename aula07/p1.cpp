#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;

int count(const string& fname, const string& word){
    int count = 0;
    ifstream in(fname);
    string w;
    string up(word);

    for(char& c: up)
        c = toupper(c);
    
    while(in >> w){
        for(char& c : w)
            c = toupper(c);
        if(w == word) count++;
    }
    return count;
}