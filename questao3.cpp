#include <iostream>
#include <cctype>

using namespace std;

int contarCaracteres(const string& S, int index = 0)
{

    if (index >= S.size()) 
    {
        return 0;
    }

    char atual = S[index];

    if (isdigit(atual))  //|| islower(atual) || isupper(atual))
    {
        return 1 + contarCaracteres(S, index + 1);
    }

    return contarCaracteres(S, index + 1);

}

string inverterString(const string& S, int index = 0) {

    if (index >= S.size()) 
    {
        return "";
    }

    string restanteInvertido = inverterString(S, index + 1);

    return restanteInvertido + S[index];
}


int main()
{
    string S = "AB2CD4E";
    int total = contarCaracteres(S);

    cout << total << endl;

    string S_invertida = inverterString(S);
    cout << "String invertida: " << S_invertida << endl;

    return 0;
}