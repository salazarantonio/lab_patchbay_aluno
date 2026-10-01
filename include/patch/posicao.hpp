#ifndef PATCH_POSICAO_HPP
#define PATCH_POSICAO_HPP

namespace {
    struct posicao {
        int fileira = 0;
        int coluna = 0;
    };

    [[nodiscard]] inline bool mesma(posicao a, posicao b) {
        return (a.fileira == b.fileira) && (a.coluna == b.coluna);
    }
}

#endif