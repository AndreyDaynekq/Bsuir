#include <iostream>
using namespace std;
// Найти максимальный элемент в массиве ai (i=1, 2, n), 
// используя очевидное соотношение max(a1, a2, an) = max[max(a1, a2, an – 1), an].
int max(int*, int);
int max2(int*, int);
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << max2(arr, n);
}

int max(int *arr, int n)
{
    if (n == 1) return *arr; 
    int count = n / 2; 
    return max(max(arr, count), max(arr + count, n - count));
}
int max2(int *arr, int n)
{
    if(n != 0)
    {
        if(max(arr, n - 1) < arr[n])
    {
        return arr[n];
    }
    else if(max(arr, n - 1) > arr[n])
    {
        return arr[n - 1];
    }
    }
}