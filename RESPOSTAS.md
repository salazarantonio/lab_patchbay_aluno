# RESPOSTAS.md

Responda em uma ou duas frases cada. Nao consulte a resposta antes de tentar.

## 1. Sistemas de tipos

(a) C++ e estatico ou dinamico? Forte ou fraco? Justifique cada uma das duas
    respostas com uma construcao da linguagem.

(b) `auto x = 3.14;` torna C++ mais dinamico? Por que?

## 2. Tipo proprio

(c) `set_nivel` recebe `decibeis`, e nao `int`. Que erro isso impede, que um
    `int` nao impediria? Escreva a linha de codigo que passaria a compilar se
    o parametro fosse `int`.

(d) Por que o construtor de `decibeis` precisa de `explicit`? O que voltaria a
    ser possivel sem ele?

## 3. Agregado e classe

(e) `posicao` tem campos publicos e `ponto` nao. Em uma frase: o que decide
    entre as duas formas?

(f) Cite uma invariante de `ponto` e uma de `painel`, e diga o que aconteceria
    com o programa se cada uma delas nao fosse garantida pela classe.

## 4. Const

(g) Por que `em()` precisa das duas sobrecargas? O que quebraria se existisse
    so a versao que devolve `ponto&`? E se existisse so a `const ponto&`?
    R: 

(h) `ocupada()` e metodo `const`. O que aconteceria, exatamente, se voce
    tirasse esse `const`? Cite o codigo do teste que pararia de compilar.

## 5. Despacho

(i) Quantos ramos tem `conectar` com 3 tipos de conector? E se aparecesse um
    quarto, `speakon`?

(j) Nenhum mecanismo de C++ escolheu a resposta por voce em `conectar`. Por
    que `virtual` (que voce vera na Aula 11) tambem nao resolveria esse caso?
