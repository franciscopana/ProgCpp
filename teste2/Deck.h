#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Tile.h"

using namespace std;

//! Represents available tiles.
class Deck {
public:
  // Constructor
  Deck(const vector<Tile>& tiles) : tiles_(tiles) { }
  // Remove all tiles from deck compatible with given tile
  int remove_all_compatible_with(const Tile& t); 
  // Show tiles in deck
  void show() const { 
    cout << "[ ";
    for (auto t : tiles_) { t.show(); cout << ' '; }
    cout << "]\n";
  }
private:
  vector<Tile> tiles_;
};

#endif
