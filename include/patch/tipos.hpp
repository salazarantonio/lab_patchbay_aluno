#ifndef PATCH_TIPOS_HPP
#define PATCH_TIPOS_HPP

namespace patch {
    struct decibeis {
        explicit decibeis(int v) : valor(v) {}
        int valor;
    };

    struct ohms {
        explicit ohms(int v) : valor(v) {}
        int valor;
    };

    enum class tipo {xlr, trs, rca};

    enum class ligacao {direta, precisa_adaptador, incompativel};
}

#endif