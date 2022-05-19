#include <iostream>
#include "p5.cpp"

using namespace std;

int main(){		
    calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
    show_file("p5_test2_out.txt");
    return 0;
}