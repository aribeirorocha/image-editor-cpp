//
// Created by gusta on 19/05/2025.
//
#include "Command/VMirror.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog::command {

    VMirror::VMirror() : Command("v_mirror") {}

    VMirror::~VMirror() {}

    Image *VMirror::apply(Image *img) {
        int width = img->width();
        int height = img->height();

        // Espelha verticalmente, trocando as linhas de cima com as de baixo
        for (int y = 0; y < height / 2; ++y) {
            for (int x = 0; x < width; ++x) {
                Color temp = img->at(x, y);
                img->at(x, y) = img->at(x, height - 1 - y);
                img->at(x, height - 1 - y) = temp;
            }
        }

        return img;
    }

    std::string VMirror::toString() const {
        std::ostringstream ss;
        ss << name();
        return ss.str();
    }

}