//
// Created by gusta on 19/05/2025.
//
#include "Command/Fill.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Fill::Fill(int x, int y, int w, int h, const Color &fill_color)
            : Command("Fill"), x(x), y(y), w(w), h(h), fill_color(fill_color) {}

        Fill::~Fill() {}

        Image *Fill::apply(Image *img) {
            // Limita a área para dentro dos limites da imagem
            int x_end = std::min(x + w, img->width());
            int y_end = std::min(y + h, img->height());

            // Percorre pixels da área definida, preenchendo com fill_color
            for (int j = y; j < y_end; j++) {
                for (int i = x; i < x_end; i++) {
                    // Só modifica pixels dentro da imagem
                    if (i >= 0 && j >= 0) {
                        img->set(i, j, fill_color);
                    }
                }
            }

            return img; // Retorna a imagem modificada
        }

        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h << " color:" << fill_color;
            return ss.str();
        }

    }
}