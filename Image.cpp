#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill)//cria imagem com largura w, altura h, preenchida com a cor 'fill'
    : width_(w), height_(h), pixels_(w * h, fill) {}//w * h é o numero total de pixeis

    Image::~Image() {
    }

    int Image::width() const {
        return width_;
    }

    int Image::height() const {
        return height_;
    }




    Color &Image::at(int x, int y) { //calcula o valor mutavel da posicao(x,y), dentro das restricoes x e y
        if (x >= 0 && x < width() && y >= 0 && y < height()) {
        return pixels_[y * width_ + x];
    }
        throw std::out_of_range("Image::at - pixel out of bounds");
    }


    const Color &Image::at(int x, int y) const {//calcula o valor "read only"
        //da posicao(x,y), dentro das restricoes x e y
        if (x >= 0 && x < width() && y >= 0 && y < height()) {
            return pixels_[y * width_ + x];
        }
        throw std::out_of_range("Image::at - pixel out of bounds");
    }
