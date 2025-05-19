//
// Created by gusta on 19/05/2025.
//

#ifndef HMIRROR_HPP
#define HMIRROR_HPP
#include "Command.hpp"

namespace prog {
    namespace command {
        class HMirror : public Command {
        public:
            HMirror();

            ~HMirror();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}


#endif //HMIRROR_HPP
