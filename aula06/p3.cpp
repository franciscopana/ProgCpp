#include <vector>
#include <iostream>
using namespace std;

//! Print vector with elements of type T.
template <typename T>
void print(const vector<T>& v) {
    cout << "[ ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << "]\n";
}

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max) {
    for (T &x: v) {
        if (x < min) x = min;
        if (x > max) x = max;
    }
}
