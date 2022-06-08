#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//! Show file contents with line number information and 
//! the '|' character indicating the begining and end of lines.
void print(const std::string& file) {
  ifstream in(file);
  size_t line_nr = 1;
  for (string line; getline(in, line);) {
     cout << line_nr << "|" << line << "|\n";
     line_nr++;
  }
}

void strUpper(string& in){
  for(char& c : in) c = toupper(c);
  return;
}

void normalise(const string& input_fname, const string& output_fname){
  ifstream in(input_fname);
  ofstream out(output_fname);
  string line;
  bool firstLine = false;
  
  while(in.peek()!=EOF){
    getline(in,line);
    string word;
    if(line != ""){
      if(!firstLine) firstLine = true;
      else out << '\n';
      line.erase(0,line.find_first_not_of(' '));
      line.erase(line.find_last_not_of(' ')+1);
      strUpper(line);
      out << line;
    }
  }
}