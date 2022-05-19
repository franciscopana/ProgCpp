#include <iostream>
#include "node.cpp"

using namespace std;

int main(){
    node* a = build(1, build(3, build(5, nullptr)));
    node* b = build(2, build(4, build(6, build(7, nullptr))));
    node* c = merge_sorted(a,b);
    print(c);
    destroy(a); destroy(b); destroy(c);
    return 0;
}