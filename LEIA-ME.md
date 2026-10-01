# LAB · Painel de conexoes

Laboratorio preparatorio. Nao vale nota. A solucao de referencia e publicada
junto com o enunciado -- mas so olhe depois de tentar.

Voce recebe DOIS arquivos: este enunciado e `testes/test_patch.cpp`.
Todo o resto -- as classes, os cabecalhos, o `CMakeLists.txt` -- e seu.

    patchbay/
      LEIA-ME.md              <- dado
      RESPOSTAS.md            <- dado (voce preenche)
      testes/test_patch.cpp   <- dado. NAO altere.
      CMakeLists.txt          <- voce escreve
      include/patch/*.hpp     <- voce escreve
      src/*.cpp               <- voce escreve

O teste e a especificacao: ele diz os nomes, as assinaturas e o comportamento.
Quando `ctest` passar sem nenhum aviso de compilador, o laboratorio acabou.

    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    cmake --build build --parallel
    ctest --test-dir build --output-on-failure
