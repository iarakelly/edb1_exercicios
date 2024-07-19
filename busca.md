# IMD0029 – ESTRUTURAS DE DADOS BÁSICAS I
# PROF. EIJI ADACHI M. BARBOSA

## Exercícios de Algoritmos de Busca


### Questão 1
Dados como entrada um inteiro X e um array A contendo N inteiros distintos, o problema Soma-2 é definido como o problema de determinar se existem dois índices i e j tais que A[i] + A[j] == X.  Neste contexto, implemente duas funções para o problema Soma-2 com complexidades $\theta(n^2)$ e $\theta(n * lg(n))$. Para a solução $\theta(n * lg(n))$, considere que o array de entrada já está ordenado.

### Questão 2 
Considere um array A contendo N inteiros, com possíveis repetições, já ordenado. Neste contexto, implemente funções que recebe como entrada um inteiro K e retorna: 

* Um índice i tal que A[i] == K, sendo A[i] o elemento igual a K que está mais a esquerda no array A. 

* Quantos elementos em A tem valor igual a K. 

Ambas funções devem ter complexidade $\theta(lg(n) )$. 

Dica: para a segunda função, use duas versões modificadas da busca binária, uma para encontrar o elemento mais à esquerda e outra para encontrar o elemento mais à direita.

### Questão 3 
Implemente uma função que implementa o algoritmo de busca ternária, isto é, um algoritmo de busca que divide o seu espaço de busca em três. Faça duas versões da busca ternária: uma iterativa e outra recursiva. Qual a complexidade do algoritmo de busca ternária?

### Questão 4 
Sequências bitônicas são aquelas que possuem duas sequências, sendo uma sequência inicial crescente, seguida de uma sequência decrescente. Ou seja, os elementos de uma sequência bitônica obedecem a seguinte relação:
 
$A_0 < A_1 < ... < A_{i-1} < A_i > A_{i+1} > ... > A_n$
 
Considere que um array bitônico é um array de inteiros sem repetições cujos elementos representam uma sequência bitônica. Dado este contexto, implemente:

* Uma função que recebe como entrada um array de inteiros e o seu tamanho e verifica se esse array é bitônico ou não.
* Uma função que recebe como entrada um array bitônico e retorna o índice do pico, isto é, o elemento $A_i$. Sua solução deverá ter complexidade $\theta(lg(n) )$.
* Uma função que recebe como entrada um array bitônico A e um número inteiro K e retorna o índice i tal que A[i] == K, ou seja, que realiza a busca de K no array bitônico A. Sua solução deverá ter complexidade $\theta(lg(n) )$.

### Questão 5 
Considere que um array inicialmente ordenado foi deslocado a direita sem querer e não se sabe quantas vezes ele foi deslocado a direita. Um deslocamento a direita de um array faz com que o último elemento do array torne-se o primeiro. Por exemplo: dado o array de entrada {1, 2, 3, 4,5, 6, 7, 8, 9, 10}, após 3 deslocamentos a direita, o array estará da seguinte forma: {8, 9, 10, 1, 2, 3, 4, 5, 6, 7}. 

Neste contexto, implemente : 
* Uma função que recebe como entrada um array A que foi deslocado a direita e retorna o número de vezes que este array foi deslocado a direita. 
* Uma função que recebe como entrada um array A que foi deslocado a direita e um inteiro K e retorna o índice i tal que A[i] == K, ou seja, que realiza a busca de K no array A. 

Ambas soluções deverão ter complexidade $\theta(lg(n) )$.

### Questão 6
Implemente uma função que recebe como entrada um array de inteiros A de tamanho N e que possui valores repetidos e retorna o número mais frequente, isto é, o valor que tem o maior número de repetições no array. Caso haja empate, isto é, caso existam dois valores com o mesmo número de repetições, este algoritmo deve retornar o valor que aparece primeiro da esquerda para direita do vetor. Esta solução deve ter complexidade $\theta(n*lg(n))$. 

Dica: Reuse a função da Questão 2 que conta quantos elementos em A tem valor igual a K.
