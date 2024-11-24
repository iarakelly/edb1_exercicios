#include <iostream>
#include <limits.h>

using namespace std;

void Selection1(int a[], int tam)
{
    int menor;
    int arraynovo[5];

    for (int i = 0; i < tam; i++)
    {

    menor = a[i];
    int posicao = -1;
        for(int j = 0; j < tam; j++)
        {
            if(a[j] < menor)
            {
                menor = a[j];
                posicao = j; // salva a posiçao do menor
            }
           // a[j] = INT_MAX;         
        }
        a[posicao] = INT_MAX; 
        arraynovo[i] = menor;
    }
    

    for (int i = 0; i < 5; i++) //print no array novo local
    {
        cout <<  " " << arraynovo[i];
    }

};


int main()
{

    int array[5] = {6, 9, 1, 5, 7};
    int tamanho = sizeof(array)/sizeof(int);

    for (int i = 0; i < 5; i++)
    {
        cout <<  " " << array[i];
    }

    Selection1(array, tamanho);

    return 0;
}