#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double average(const string& fname){
    int count = 0;
    double total = 0;
    ifstream file(fname);
    while(!file.eof()){
        double val;
        if(file >> val){
            total += val;
            count++;
        }
        else{
            file.clear();
            file.ignore(1);
        }
    }
    return total/count;
}