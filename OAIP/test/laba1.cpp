#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <int> lol;
    for(int i = 0; i < 10; i++)
    {
        lol.push(i);
    }
    for(int i = 0; i < 10; i++)
    {
       cout << lol.top();
       lol.pop();
    }
}