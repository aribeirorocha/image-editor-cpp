//
// Created by gusta on 19/05/2025.
//

#ifndef FILL_HPP
#define FILL_HPP
#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            // Construtor recebe a posição (x,y), dimensão (w,h) e a cor para preencher
            Fill(int x, int y, int w, int h, const Color &fill_color);

            ~Fill();

            // Aplica o preenchimento na região especificada da imagem
            Image *apply(Image *img) override;

            // Representação textual do comando
            std::string toString() const override;

        private:
            int x, y, w, h;
            Color fill_color;
        };
    }
}


#endif //FILL_HPP
