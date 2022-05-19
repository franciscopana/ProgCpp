#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//! Show file name and the contents.
void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

void calc_medians(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    string line;
    while(getline(in, line)){
        if(line[0] == '#') continue;
        istringstream str_line(line);
        vector<double> vec;
        double val;
    }
}