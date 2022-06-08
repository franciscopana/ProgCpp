#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cfloat>

using namespace std;

//! Show file name and its contents.
void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

bool average(const string& input_fname, const string& output_fname){
    ifstream reader(input_fname);
    ofstream writter(output_fname);

    int lines = 0;
    for(string line; getline(reader, line);){
        istringstream in_line(line);
        double value, sum = 0, counter=0;
        while(in_line >> value){
            sum += value;
            counter++;
        }
        writter <<setprecision(3) << fixed << sum/counter << '\n';
        lines++;
    }
    writter << "lines=" <<  lines;
    return true;
}

int main(){
    return 0;
}