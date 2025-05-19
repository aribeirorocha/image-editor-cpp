//
// Created by gusta on 19/05/2025.
//
#include "Command/Replace.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Replace::Replace(const Color &from, const Color &to) : Command("Replace"), from(from), to(to) {}

        Replace::~Replace() {}

        Image *Replace::apply(Image *img) {
            // Percorre todos os pixels da imagem
            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    Color current = img->get(x, y);
                    // Se o pixel for igual à cor 'from', substitui pela cor 'to'
                    if (current == from) {
                        img->set(x, y, to);
                    }
                }
            }
            return img; // Retorna a imagem modificada
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " from:" << from << " to:" << to;
            return ss.str();
        }

    }
}