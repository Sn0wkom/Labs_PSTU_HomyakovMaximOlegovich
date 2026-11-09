#include <iostream>

using namespace std;

void sort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++) {
            int t = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > t; j -= gap)
                a[j] = a[j - gap];
            a[j] = t;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "RU");

    int n, a[20];

    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a,n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
