#include <iostream>
using namespace std;

//A(0, n) = n + 1;
//A(m, 0) = A(m – 1, 1) при m > 0;
//A(m, n) = A(m – 1, A(m, n – 1)) при m > 0 и n > 0.
int Akker(int, int);
int AkkerN(int, int);//A(0, n) = n + 1;
//A(m, 0) = A(m – 1, 1) при m > 0;
//A(m, n) = A(m – 1, A(m, n – 1)) при m > 0 и n > 0.
int AkkerN(int, int);
int main()
{
   unsigned int m, n;
   cin >> m >> n;
   cout << Akker(m, n); 
}

int Akker(int m, int n)
{
    if(m == 0)
    {
        return (n + 1);
    }
    else if(m > 0 && n > 0)
    {
        cout << "1" << endl;
        return Akker(m - 1, Akker(m, n - 1));
    }
    else
    {
        return Akker(m - 1, 1);
    }
}
int AkkerN(int m, int n)
{
    unsigned int result = 0;
    unsigned int m1, n1;
    if(m == 0)
    {
        return (n - 1);
    }
    else
    {
        for(int i = 0; i < n; i++)
        {

        }
    }
}
