#ifndef PATCH_PONTO_HPP
#define PATCH_PONTO_HPP

#include <string>
#include "patch/tipos.hpp"
#include "patch/posicao.hpp"

namespace patch {

    class ponto {
        public:
            ponto(const std::string& rotulo, tipo conector, posicao onde);

            void set_nivel(decibeis n);
            void set_impedancia(ohms z);

            [[nodiscard]] const std::string& rotulo() const;
            [[nodiscard]] tipo conector() const;
            [[nodiscard]] posicao onde() const;
            [[nodiscard]] int nivel() const;         // em dB
            [[nodiscard]] int impedancia() const;    // em ohms

        private:
            std::string rotulo_;
            tipo conector_;
            posicao onde_;

            int nivel_ = 0;
            int impedancia_ = 600;
    };
}

#endif