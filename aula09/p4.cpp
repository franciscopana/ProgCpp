#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>

using namespace std;

template <typename T, typename V>
class Pair{
    public:
        Pair(T first, V second){
            first_ = first;
            second_ = second;
        }
        T get_first() const {return first_;}
        V get_second() const {return second_;}
        void show(){cout << '{' << first_ << ',' << second_ << '}';}
    private:
        T first_;
        V second_;
};

template <typename T, typename V>
void sort_by_first(vector<Pair<T,V>>& v){
    sort(v.begin(), v.end(), [](Pair<T,V> a, Pair<T,V> b) {
        return a.get_first() < b.get_first();
    });
}

template <typename T, typename V>
void sort_by_second(vector<Pair<T,V>>& v){
    sort(v.begin(), v.end(), [](Pair<T,V> a, Pair<T,V> b) {
        return a.get_second() < b.get_second();
    });
}

template <typename T, typename V>
void show(vector<Pair<T,V>> v){
    cout << '{';
    for(size_t i = 0; i < v.size(); i++){
        v[i].show();
    }
    cout << '}';
}

int main(){
    return 0;
}