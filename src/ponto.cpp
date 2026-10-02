#include "patch/ponto.hpp"

using std::string;

namespace patch {

    ponto::ponto(const string& rotulo, tipo conector, posicao onde) : rotulo_{rotulo}, conector_{conector}, onde_{onde} {}

    void ponto::set_nivel(decibeis n) {
        // nível satura no piso e no teto
        if (n.valor < -60) {
            nivel_ = -60; 
        } else if (n.valor > 24) {
            nivel_ = 24;
        }
    }

    void ponto::set_impedancia(ohms z) {
        // nao aceita valores invalidos
        if (z.valor > 0) {
            impedancia_ = z.valor;
        }
    }

    const string& ponto::rotulo() const {
        return rotulo_;
    }

    tipo ponto::conector() const {
        return conector_;
    }

    posicao ponto::onde() const {
        return onde_;
    }

    int ponto::nivel() const {
        return nivel_;
    }

    int ponto::impedancia() const {
        return impedancia_;
    }
}