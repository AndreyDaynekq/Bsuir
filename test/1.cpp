
// 2. Одномерный динамический массив, с n элементами (ввод с Клавы). 
// Найти среднее арифметическое положительный элементов. 
// Заменить элементы под нечетными номерами полусуммой соседних элементов. Вывести исходный массив и результат вычислений. 
// Очистить память.
#include <iostream>
using namespace std;
void func(double *arr, int n)
{
    double sred;
    int kol = 0;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            sum += arr[i];
            kol++;
        }
    }
    sred = sum / kol;
    cout << "Sred arifm: " << sred << endl;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 != 0)
        {
            arr[i] = (arr[i-1] + arr[i+1]) / 2;
        }
    }

}
int main()
{
    int n;
    cin >> n;
    double *arr = new double[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    func(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}