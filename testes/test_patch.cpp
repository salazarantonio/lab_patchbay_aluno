// ARQUIVO DADO. Nao altere. Ele e a especificacao executavel do laboratorio.
#include <catch2/catch_test_macros.hpp>

#include <type_traits>

#include "patch/conectar.hpp"
#include "patch/painel.hpp"
#include "patch/ponto.hpp"
#include "patch/posicao.hpp"
#include "patch/tipos.hpp"

// ---------------------------------------------------------------- PARTE 1
TEST_CASE("P1 · decibeis e ohms sao tipos proprios, e nao int disfarcado") {
  const decibeis n{-12};
  const ohms z{600};
  REQUIRE(n.valor == -12);
  REQUIRE(z.valor == 600);

  static_assert(!std::is_convertible<int, decibeis>::value,
                "um int solto nao pode virar decibeis sozinho");
  static_assert(!std::is_convertible<int, ohms>::value,
                "um int solto nao pode virar ohms sozinho");
  static_assert(!std::is_convertible<ohms, decibeis>::value,
                "impedancia nao e nivel");
  static_assert(!std::is_convertible<decibeis, ohms>::value,
                "nivel nao e impedancia");
}

// ---------------------------------------------------------------- PARTE 2
TEST_CASE("P2 · posicao e um agregado: campos publicos, sem porta") {
  posicao a{2, 5};
  REQUIRE(a.fileira == 2);
  REQUIRE(a.coluna == 5);

  a.coluna = -3;                       // permitido: nao ha invariante
  REQUIRE(mesma(a, posicao{2, -3}));
  REQUIRE_FALSE(mesma(a, posicao{2, 5}));

  const posicao padrao{};              // os dois campos comecam em zero
  REQUIRE(mesma(padrao, posicao{0, 0}));
}

// ---------------------------------------------------------------- PARTE 3
TEST_CASE("P3 · o ponto satura o nivel entre -60 e +24 dB") {
  ponto p{"voz", tipo::xlr, posicao{1, 1}};
  REQUIRE(p.nivel() == 0);

  p.set_nivel(decibeis{-12});
  REQUIRE(p.nivel() == -12);

  p.set_nivel(decibeis{-999});
  REQUIRE(p.nivel() == -60);

  p.set_nivel(decibeis{999});
  REQUIRE(p.nivel() == 24);
}

TEST_CASE("P3 · a impedancia e sempre maior que zero") {
  ponto p{"linha", tipo::trs, posicao{1, 2}};
  REQUIRE(p.impedancia() == 600);

  p.set_impedancia(ohms{10000});
  REQUIRE(p.impedancia() == 10000);

  p.set_impedancia(ohms{0});           // invalido: mantem o anterior
  REQUIRE(p.impedancia() == 10000);

  p.set_impedancia(ohms{-5});
  REQUIRE(p.impedancia() == 10000);
}

TEST_CASE("P3 · o ponto guarda rotulo, conector e casa") {
  const ponto p{"retorno 1", tipo::rca, posicao{3, 4}};
  REQUIRE(p.rotulo() == "retorno 1");
  REQUIRE(p.conector() == tipo::rca);
  REQUIRE(mesma(p.onde(), posicao{3, 4}));
}

// ---------------------------------------------------------------- PARTE 4
TEST_CASE("P4 · o painel recusa duas casas iguais") {
  painel p{"principal"};
  REQUIRE(p.vazio());

  REQUIRE(p.instalar(ponto{"voz", tipo::xlr, posicao{1, 1}}));
  REQUIRE_FALSE(p.instalar(ponto{"outro", tipo::trs, posicao{1, 1}}));
  REQUIRE(p.instalar(ponto{"linha", tipo::trs, posicao{1, 2}}));

  REQUIRE(p.quantidade() == 2);
  REQUIRE(p.ocupada(posicao{1, 1}));
  REQUIRE_FALSE(p.ocupada(posicao{9, 9}));
}

TEST_CASE("P4 · em() da leitura no objeto const e escrita no nao-const") {
  painel p{"principal"};
  p.instalar(ponto{"voz", tipo::xlr, posicao{1, 1}});

  const painel& somente_leitura = p;
  REQUIRE(somente_leitura.em(0).rotulo() == "voz");   // so a sobrecarga const
  REQUIRE(somente_leitura.em(0).nivel() == 0);

  p.em(0).set_nivel(decibeis{-6});                    // so a nao-const
  REQUIRE(somente_leitura.em(0).nivel() == -6);
}

// ---------------------------------------------------------------- PARTE 5
TEST_CASE("P5 · conectar decide pelos DOIS pontos") {
  const ponto xlr_{"a", tipo::xlr, posicao{1, 1}};
  const ponto trs_{"b", tipo::trs, posicao{1, 2}};
  const ponto rca_{"c", tipo::rca, posicao{1, 3}};

  REQUIRE(conectar(xlr_, xlr_) == ligacao::direta);
  REQUIRE(conectar(trs_, trs_) == ligacao::direta);
  REQUIRE(conectar(rca_, rca_) == ligacao::direta);

  REQUIRE(conectar(xlr_, trs_) == ligacao::precisa_adaptador);
  REQUIRE(conectar(trs_, xlr_) == ligacao::precisa_adaptador);
  REQUIRE(conectar(trs_, rca_) == ligacao::precisa_adaptador);
  REQUIRE(conectar(rca_, trs_) == ligacao::precisa_adaptador);

  REQUIRE(conectar(xlr_, rca_) == ligacao::incompativel);
  REQUIRE(conectar(rca_, xlr_) == ligacao::incompativel);
}
