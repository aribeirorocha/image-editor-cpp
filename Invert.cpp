//
// Created by gusta on 19/05/2025.
//
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {}

        Image* Invert::apply(Image* img) {
            // Cria nova imagem com as mesmas dimensões
            Image* new_img = new Image(*img); // cópia da imagem original

            for (int y = 0; y < new_img->height(); ++y) {
                for (int x = 0; x < new_img->width(); ++x) {
                    Color c = new_img->at(x, y);
                    Color inverted(255 - c.red(), 255 - c.green(), 255 - c.blue());
                    new_img->at(x, y) = inverted;
                }
            }

            delete img; // liberta imagem original
            return new_img;
        }

        std::string Invert::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
