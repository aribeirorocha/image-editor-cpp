//
// Created by gusta on 19/05/2025.
//

#ifndef TOGRAYSCALE_HPP
#define TOGRAYSCALE_HPP
#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class ToGrayScale : public Command {
        public:
            ToGrayScale();

            ~ToGrayScale();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}

#endif //TOGRAYSCALE_HPP
