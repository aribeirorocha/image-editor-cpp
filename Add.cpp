//
// Created by gusta on 19/05/2025.
//
#include "Command/Add.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog::command {

    Add::Add(const std::string &filename, const Color &neutral, int x, int y)
        : Command("add"), filename(filename), neutral(neutral), x(x), y(y) {}

    Add::~Add() {}

    Image *Add::apply(Image *img) {
        // Carrega imagem da origem
        Image *overlay = new Image(filename);

        int srcWidth = overlay->width();
        int srcHeight = overlay->height();
        int destWidth = img->width();
        int destHeight = img->height();

        // Copia pixel a pixel da overlay para a imagem de destino, se não for da cor neutra
        for (int oy = 0; oy < srcHeight; ++oy) {
            for (int ox = 0; ox < srcWidth; ++ox) {
                int tx = x + ox;
                int ty = y + oy;

                if (tx < 0 || ty < 0 || tx >= destWidth || ty >= destHeight)
                    continue; // Ignora fora dos limites

                Color c = overlay->at(ox, oy);
                if (c != neutral) {
                    img->at(tx, ty) = c;
                }
            }
        }

        delete overlay;
        return img;
    }

    std::string Add::toString() const {
        std::ostringstream ss;
        ss << name() << " file:" << filename << " neutral:" << neutral << " x:" << x << " y:" << y;
        return ss.str();
    }

}