#include <iostream>
#include <iomanip>
#include <vector>
#include "Tile.h"
#include "Deck.h"

bool Tile::compatible_with(const Tile& t) const{
    return(s1_ == t.s1_ || s1_ == t.s2_ || s2_ == t.s1_ || s2_ == t.s2_);
}

int Deck::remove_all_compatible_with(const Tile& t){
    vector<Tile> vnew;
    int result = 0;
    for(Tile t2 : tiles_){
        if(t2.compatible_with(t)){
            result++;
        }
        else{
            vnew.push_back(t2);
        }
    }
    tiles_ = vnew;
    return result;
}

int main(){
    return 0;
}