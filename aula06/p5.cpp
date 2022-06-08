#include <vector>
#include <iostream>
using namespace std;

struct sm_entry {
    size_t row;
    size_t col;
    int value;
};

typedef vector<sm_entry> smatrix;

//! Print a sparse matrix.
void print(const smatrix& sm) {
    cout << "[ ";
    for (sm_entry e : sm) {
        cout << '(' << e.row << ", " << e.col << ", " << e.value << ") ";
    }
    cout << "]\n";
}

void sum(const smatrix& a, const smatrix& b, smatrix& r){
    size_t pa = 0, pb = 0;
    while(pa < a.size() && pb < b.size()){
        sm_entry ma = a[pa], mb = b[pb];
        if(ma.row < mb.row){r.push_back(ma);pa++;}
        else if(ma.row > mb.row){r.push_back(mb);pb++;}
        else{
            if(ma.col < mb.col){r.push_back(ma);pa++;}
            else if(ma.col > mb.col){r.push_back(mb);pb++;}
            else{
                if(ma.value + mb.value != 0)
                    r.push_back({ma.row, ma.col, ma.value + mb.value});
                pa++; pb++;
            }
        }
    }
    while(pa < a.size()) r.push_back(a[pa++]);
    while(pb < b.size()) r.push_back(b[pb++]);
}