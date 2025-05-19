//
// Created by gusta on 19/05/2025.
//
#include "Command/Move.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog::command {

    Move::Move(int dx, int dy) : Command("Move"), dx(dx), dy(dy) {}

    Move::~Move() {}

    Image* Move::apply(Image* img) {
        int w = img->width();
        int h = img->height();
        Color fill_color = img->getFill();

        // Criar nova imagem com mesmas dimensões e cor de preenchimento
        Image* new_img = new Image(w, h, fill_color);

        // Copiar pixels válidos da imagem antiga para a nova posição
        for (int y = 0; y < h - dy; ++y) {
            for (int x = 0; x < w - dx; ++x) {
                new_img->at(x + dx, y + dy) = img->at(x, y);
            }
        }

        delete img;
        return new_img;
    }

    std::string Move::toString() const {
        std::ostringstream ss;
        ss << name() << " dx:" << dx << " dy:" << dy;
        return ss.str();
    }

}