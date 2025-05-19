//
// Created by gusta on 19/05/2025.
//

#ifndef SLIDE_HPP
#define SLIDE_HPP
#include "Command.hpp"

namespace prog::command {

    class Slide : public Command {
    public:
        Slide(int dx, int dy);
        ~Slide();

        Image *apply(Image *img) override;
        std::string toString() const override;

    private:
        int dx, dy;
    };

}
#endif //SLIDE_HPP
