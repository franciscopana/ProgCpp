#include "Color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue){
    r = red;
    g = green;
    b = blue;
}

Color::Color(const Color& b){
    r = b.r;
    g = b.g;
    this->b = b.b;
}

unsigned char Color::red() const{
    return r;
}
unsigned char Color::green() const{
    return g;
}
unsigned char Color::blue() const{
    return b;
}

bool Color::equal_to(const Color& other) const{
    return (r == other.r && g == other.g && b == other.b);
}

void Color::invert(){
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
}

const Color Color::RED = {255,0,0};
const Color Color::GREEN = {0,255,0};
const Color Color::BLUE = {0,0,255};
const Color Color::BLACK = {0,0,0};
const Color Color::WHITE = {255,255,255};