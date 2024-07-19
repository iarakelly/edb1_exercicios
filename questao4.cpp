#include <iostream>
#include <cassert>

using namespace std;

int somar(int x, int y) {
    if (y == 0) 
    {
        return x;
    }
    else
    {
        return somar(x + 1, y - 1);

    }
}

int multiplica(int x, int y)
{
    if (x == 1)
    {
        return y;
    }
    else
    {
        return y + multiplica(x-1, y);
    }
}
int exponencial(int x, int y)
{
    if(y == 1)
    {
        return x;
    }
    else
    {
       return x*(exponencial(x, y-1)); 
    }
}

int main()
{ 
   
    assert(somar(10, 33) == 43);
    assert(somar(245, 24) == 269);
    assert(multiplica(10, 33) == 330);
    assert(multiplica(9, 3) == 27);
    assert(exponencial(3, 3) == 27);
    assert(exponencial(2, 5) == 32);


    cout << "Passou nos testes" << endl;

    return 0;
}