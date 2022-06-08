#ifndef COLOR_H
#define COLOR_H

class Color{
    public:
        // constructors
        Color(unsigned char red, unsigned char green, unsigned char blue);
        Color(const Color& b);
        // Accessors
        unsigned char red() const;
        unsigned char green() const;
        unsigned char blue() const;
        static const Color RED, GREEN, BLUE, BLACK, WHITE;
        // equality between two colors
        bool equal_to(const Color& other) const;
        // Invert a color
        void invert();
    private:
        unsigned char r, g, b;
};

#endif