#include "patch/painel.hpp"

using std::string;
using std::vector;
using std::size_t;

namespace patch {
    painel::painel(const string& nome) : nome_{nome} {}

    bool painel::ocupada(posicao onde) const {
        for (const auto& p : pontos_) {
            if (mesma(p.onde(), onde)) {
                return true;
            }
        }
        return false;
    }

    bool painel::instalar(const ponto& p) {
        // Invariante
        if (ocupada(p.onde())) {
            return false;
        }
        pontos_.push_back(p);
        return true;
    }

    const string& painel::nome() const {
        return nome_;
    }

    size_t painel::quantidade() const {
        return pontos_.size();
    }

    bool painel::vazio() const {
        return pontos_.empty();
    }

    const ponto& painel::em(size_t i) const {
        return pontos_[i];
    }

    ponto& painel::em(size_t i) {
        return pontos_[i];
    }
}