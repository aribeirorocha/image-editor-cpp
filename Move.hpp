//
// Created by gusta on 19/05/2025.
//

#ifndef MOVE_HPP
#define MOVE_HPP
#include "Command.hpp"

namespace prog::command {
    class Move : public Command {
    public:
        Move(int dx, int dy);
        ~Move();
        Image* apply(Image* img) override;
        std::string toString() const override;

    private:
        int dx;  // deslocamento em x
        int dy;  // deslocamento em y
    };
}
#endif //MOVE_HPP
