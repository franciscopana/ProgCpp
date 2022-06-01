#include <iostream>
#include <map>
#include <string>
 
using namespace std;

unsigned roman_to_arab(const string& roman){
    unsigned result = 0;
    map<char, unsigned> map_roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    unsigned current = 1000;
    for(char c: roman){
        unsigned value = map_roman[c];
        if(value <= current){
            result += value;
        }
        else{
            result = (result - current) + (value - current);
        }
        current = value;
    }
    return result;
}
