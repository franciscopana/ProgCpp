#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//! Show file name and its contents.
void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

void maximum(const string& input_fname, const string& output_fname){
    ifstream reader(input_fname);
    ofstream writter(output_fname);
    string line;
    int count = 0;
    double max = -1000;
    while(getline(reader, line)){
        double v;
        istringstream sline(line);
        if(sline >> v){
            writter << fixed << setprecision(3) << v << '\n';
            count++;
            if(v > max){
                max = v;
            }
        }

    }
    writter << "count=" << count << "/max="<< fixed << setprecision(3) << max;
}

int main(){
    return 0;
}