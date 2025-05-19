//
// Created by gusta on 19/05/2025.
//
#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        ToGrayScale::ToGrayScale() : Command("ToGrayScale") {}

        ToGrayScale::~ToGrayScale() {}

        Image* ToGrayScale::apply(Image* img) {
            if (!img) return nullptr;

            int width = img->width();
            int height = img->height();

            // Criar uma nova imagem com mesma dimensão e cor de preenchimento igual ao fill color da imagem original
            Image* result = new Image(width, height, img->fill_color());

            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    Color c = img->get_pixel(x, y);
                    int v = (c.r() + c.g() + c.b()) / 3;  // cinzento
                    Color gray(v, v, v);
                    result->set_pixel(x, y, gray);
                }
            }

            delete img; // remover a imagem antiga

            return result;
        }

        std::string ToGrayScale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}