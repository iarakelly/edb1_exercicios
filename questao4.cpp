#include <iostream>

using namespace std;

int somar(int X, int Y) {
    if (Y == 0) {
        return X;
    }
    return somar(X + 1, Y - 1);
}


int main()
{ 
    int soma = somar(3, 5);

    cout << soma;

    return 0;
}