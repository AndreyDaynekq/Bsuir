#include <iostream>
using namespace std;

//A(0, n) = n + 1;
//A(m, 0) = A(m – 1, 1) при m > 0;
//A(m, n) = A(m – 1, A(m, n – 1)) при m > 0 и n > 0.
int Akker(int, int);
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
    if(m == 0)
    {
        return (n + 1);
    }
    else if(m > 0 && n > 0)
    {
        for(int i = 0; i < m; m--)
        {

        }
    }
    else
    {
        m -= 1;
    }
}

//A(2,2)
//A(1, A(2, A(2, 0)))
//A(1, A(2, A(1, A(1, 0))))
//A(1, A(2, A(1, A(0, 1))))
//A(1, A(2, A(1, 2)))
//A(1, A(2, A(0, A(1, A(1, 0)))))
//A(1, A(2, A(0, A(1, A(0, 1)))))
//A(1, A(2, A(0, A(1, 2))))
//A(1, A(2, A(0, A(0, A(1, 1)))))
//A(1, A(2, A(0, A(0, A(0, A(1, 0))))))
//A(1, A(2, A(0, A(0, A(0, A(0, 1))))))
//A(1, A(2, 5))
//