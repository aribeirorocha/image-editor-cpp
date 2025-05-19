//
// Created by gusta on 19/05/2025.
//

#ifndef VMIRROR_HPP
#define VMIRROR_HPP
#include "Command.hpp"

namespace prog::command {

    class VMirror : public Command {
    public:
        VMirror();
        ~VMirror();

        Image *apply(Image *img) override;
        std::string toString() const override;
    };

}
#endif //VMIRROR_HPP
