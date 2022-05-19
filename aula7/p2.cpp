#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;
 
struct wcresult {
  unsigned int lines;
  unsigned int words; 
  unsigned int bytes; 
};

wcresult wc(const string& filename){
    wcresult res = {0,0,0};
    ifstream in(filename);
    string line, wrd;
    while (getline(in, line)){
        istringstream stream(line);
        res.bytes = line.length() +1;
        while(stream >> wrd){
            res.words++;
        }
        res.lines++;
    }
    return res;
}