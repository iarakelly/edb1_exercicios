#include <iostream>
#include <cassert>

using namespace std;

int maior(int N)
{
    if(N < 10)
    {
        return N;
    }
    else
    {
        int UltimoD = N%10;
        int resto = N/10;

        int maiorResto = maior(resto);
         
        return max(UltimoD, maiorResto);
    }

}

int contaImpares (int N)
{
    if( N < 10) //tem só 1 dígito
    {
        return ( N % 2 != 0)? 1:0;
    }
    else
    {
        int ultimoD = N % 10;
        int resto = N / 10;

        return (ultimoD % 2 != 0 ? 1:0) + contaImpares(resto);
    }
   
}

int soma(int N)
{
    if(N < 10)
    {
        return N;
    }
    else
    {
        int ultimoD = N % 10;
        int resto = N / 10;

        return ultimoD + soma(resto);
    }
}
int contarDigitos(int N)
{
    if(N < 10)
    {
        return 1;
    }
    else
    {
        return 1 + contarDigitos(N/10);
    }
}

int valorMedio(int N)
{
    int somaTotal = soma(N);
    int digitos = contarDigitos(N);

    return somaTotal/digitos;

}

void decimalParaBinario(int N) {
    if (N == 0) 
    {
        cout << N;;
    } else 
    {
        decimalParaBinario(N/2);
        cout << N %2;
    }
}

int main() 
{
    int N = 2117;

    assert( maior(2117) == 7);
    assert(contaImpares(2117)== 3);
    assert (soma(2117) == 11);
    assert (valorMedio(2117) == 2);

    cout << "Passou nos testes" << endl;

   return 0; 

} 

