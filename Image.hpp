#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

namespace prog {
    class Image {
    private:

        int width_;
        int height_;
        std::vector<Color> pixels_; //Cada pixel da imagem é uma cor, e a
        // classe Color representa exatamente isso: uma cor RGB com três
        // componentes (vermelho, verde e azul).


    public:
        Image(int w, int h, const Color &fill = {255, 255, 255});

        ~Image();//Apaga da memória

        int width() const;

        int height() const;

        Color &at(int x, int y);

        const Color &at(int x, int y) const;
    };
}
#endif
