#include <iostream>
#include <cassert>

using namespace std;

int indice_do_menor(int array[], int tamanho, int indice)
{
    if (tamanho == 0)
    {
        return indice;
    }
    else
    {
        if(array[tamanho]<array[indice])
        {
            return indice_do_menor(array, tamanho-1, tamanho);
        }
        else
        {
            return indice_do_menor(array, tamanho-1, indice);
        }
    }
}
int conta_pares(int array[], int tamanho, int inicio)
{
    if(tamanho == inicio)
    {
        return 0;
    }
    else
    {
        if ((array[inicio] %2 )== 0)
        {
            return 1 + conta_pares(array, tamanho, inicio + 1);

        }
        else
        {
            return conta_pares(array, tamanho, inicio + 1);
        }
    }
}
int soma_elementos(int array[], int tamanho, int soma)
{
    if (tamanho == 0)
    {
        return soma;
    }
    else
    {
        return soma_elementos(array, tamanho - 1, soma + array[tamanho-1]);
    }

}
int valor_medio(int array[], int tamanho, int soma)
{
    int somaV = soma_elementos(array, tamanho, soma);
    return somaV/tamanho;
}

int main()
{

    int array[] = {10, 2, 3, 9, 11, 0, 2, 20, 1, 2, 3};
    int tamanho = sizeof(array) / sizeof(int);


    assert(indice_do_menor(array, tamanho,0) == 5);
    assert(conta_pares(array, tamanho, 0)== 6 );
    assert(soma_elementos(array, tamanho, 0) == 63 );
    assert(valor_medio(array, tamanho, 0) == 5);


    cout << "Passou nos testes" << endl;

    return 0;

}