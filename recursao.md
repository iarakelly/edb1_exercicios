# IMD0029 – ESTRUTURAS DE DADOS BÁSICAS I
# PROF. EIJI ADACHI M. BARBOSA

## Exercícios de Recursão

### Questão 1
Dado como entrada um array A de tamanho N e que contém  elementos inteiros, implemente funções recursivas para:
* Encontrar o maior (ou menor) elemento do array, retornando o seu índice.
* Contar quantos elementos pares (ou ímpares) existem no array, retornando essa quantidade.
* Somar todos os elementos do array, retornando a soma.
* Calcular o valor médio dos elementos do array, retornando a parte inteira desse valor médio.

### Questão 2
Dado como entrada um número natural N, implemente funções recursivas para:
* Encontrar o maior (ou menor) dígito de N, retornando-o. Por exemplo, se N for igual a $2117$, sua função deve retornar $7$, que é o maior dígito de N.
* Contar quantos dígitos pares (ou ímpares) N possui, retornando essa quantidade. Por exemplo, se N for igual a $2117$, sua função deve retornar $1$, pois N possui $1$ dígito par (ou $3$, caso esteja contando o número de dígitos ímpares).
* Somar todos os dígitos de N, retornando a soma. Por exemplo, se N for igual a $2117$, sua função deve retornar $11$, que é o resultado da soma $2 + 1 + 1 + 7$.
* Calcular o valor médio dos dígitos de N, retornando a parte inteira desse valor médio. Por exemplo, se N for igual a $2117$, o valor médio dos seus dígitos é $2.75$ (considerando que o valor médio é calculado como $(2+1+1+7)/4 )$, logo, sua função deve retornar $2$.
* Converter N de decimal para binário. Para esta função, basta imprimir no próprio terminal o valor de N em binário.

### Questão 3
Dada como entrada uma string S, implemente funções recursivas para:
* Contar quantos caracteres são dígitos (ou letras minúsculas, ou letras maiúsculas).
* Inverter a ordem dos caracteres. Por exemplo, se S for igual a "ABCDE", sua função deve retornar "EDCBA".

### Questão 4
Implemente funções recursivas para:
* Somar dois números inteiros, considerando que $X + Y$ pode ser expresso como $X + 1 + 1 + ... + 1$, em que 1 é somado a X um total de Y vezes.
* Multiplicar dois números inteiros, considerando que $X * Y$ pode ser expresso como $Y + Y + ... + Y$, em que Y é somado sucessivamente um total de X vezes.
* Realizar a exponenciação de dois números inteiros, considerando que $X^Y$ pode ser expresso como $X * X * ... * X$, em que X é multiplicado sucessivamente um total de Y vezes.
