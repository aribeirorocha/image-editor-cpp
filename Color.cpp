#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() :
      r_(0),g_(0),b_(0){}



    Color::Color(const Color &other):
      r_(other.r_), g_ ( other.g_), b_ (other.b_) {}

    Color::Color(rgb_value red, rgb_value green, rgb_value blue):
    r_ (red) , g_(green), b_(blue) {}

    rgb_value Color::red() const {
        return r_;
    }

    rgb_value Color::green() const {
        return g_;
    }

    rgb_value Color::blue() const {
        return b_;
    }



    rgb_value &Color::red() {
        return r_;
    }

    rgb_value &Color::green() {
        return g_;
    }

    rgb_value &Color::blue() {
        return b_;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}

