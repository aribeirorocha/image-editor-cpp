//
// Created by gusta on 19/05/2025.
//
#include "Command/HMirror.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        HMirror::HMirror() : Command("HMirror") {}

        HMirror::~HMirror() {}

        Image* HMirror::apply(Image* img) {
            int w = img->width();
            int h = img->height();

            // Cria uma cópia da imagem para modificar
            Image* new_img = new Image(*img);

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w / 2; ++x) {
                    // Pega os pixels a serem trocados
                    Color left = img->getPixel(x, y);
                    Color right = img->getPixel(w - 1 - x, y);

                    // Troca os pixels na nova imagem
                    new_img->setPixel(x, y, right);
                    new_img->setPixel(w - 1 - x, y, left);
                }
            }

            // Apaga a imagem antiga e devolve a nova invertida horizontalmente
            delete img;
            return new_img;
        }

        std::string HMirror::toString() const {
            return name();
        }

    }
}