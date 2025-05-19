//
// Created by gusta on 19/05/2025.
//

#ifndef REPLACE_HPP
#define REPLACE_HPP
#include "Command.hpp"
#include "Color.hpp"

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            // Construtor recebe as cores a substituir e a cor substituta
            Replace(const Color &from, const Color &to);

            ~Replace();

            // Aplica a substituição na imagem
            Image *apply(Image *img) override;

            // Representação textual do comando
            std::string toString() const override;

        private:
            Color from; // cor a ser substituída
            Color to;   // cor substituta
        };
    }
}


#endif //PROJECT_REPLACE_HPP

#endif //REPLACE_HPP
