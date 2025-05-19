//
// Created by gusta on 19/05/2025.
//
#include "Command/Slide.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog::command {

    Slide::Slide(int dx, int dy) : Command("Slide"), dx(dx), dy(dy) {}

    Slide::~Slide() {}

    Image *Slide::apply(Image *img) {
        int w = img->width();
        int h = img->height();

        // Cria nova imagem com as mesmas dimensões e cor de preenchimento
        Image *new_img = new Image(w, h, img->get_fill());

        // Aplica deslocamento com wrap-around ("warp" ou slide)
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int src_x = (x - dx + w) % w;
                int src_y = (y - dy + h) % h;
                new_img->at(x, y) = img->at(src_x, src_y);
            }
        }

        delete img;
        return new_img;
    }

    std::string Slide::toString() const {
        std::ostringstream ss;
        ss << name() << " dx:" << dx << " dy:" << dy;
        return ss.str();
    }

}