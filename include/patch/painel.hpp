#ifndef PATCH_PAINEL_HPP
#define PATCH_PAINEL_HPP

#include <string>
#include <vector>
#include "patch/ponto.hpp"
#include "patch/posicao.hpp"

namespace patch {
    class painel {
        public:
            explicit painel(const std::string& nome);
            
            /// Recusa casa ja ocupada. Devolve false quando recusa.
            bool instalar(const ponto& p);
            
            [[nodiscard]] const std::string& nome() const;
            [[nodiscard]] std::size_t quantidade() const;
            [[nodiscard]] bool vazio() const;
            [[nodiscard]] bool ocupada(posicao onde) const;
            
            // O par: uma da leitura, outra da escrita.
            [[nodiscard]] const ponto& em(std::size_t i) const;
            [[nodiscard]] ponto&       em(std::size_t i);
        
        private:
            std::string nome_;
            std::vector<ponto> pontos_;
    };
}

#endif