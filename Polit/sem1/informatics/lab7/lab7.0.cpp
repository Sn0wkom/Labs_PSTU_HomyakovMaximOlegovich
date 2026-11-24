#include <iostream>
#include <cstdlib>

using namespace std;

void print(const int a[], int n) 
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void sdvig(int a[], int n)
{
    if (n <= 1)
        return;

    int k = abs(a[0]) % n;

    for (int i = 0; i < k; i++)
    {
        int f = a[0];
        for (int j = 0; j < n - 1; j++)
            a[j] = a[j + 1];
        a[n - 1] = f;
    }
}

void sdvig(int a[], int n, bool flag)
{
    if (n <= 1)
        return;

    int k = abs(a[n - 1]) % n;

    for (int i = 0; i < k; i++)
    {
        int f = a[n - 1];
        for (int j = n - 1; j > 0; j--)
            a[j] = a[j - 1];
        a[0] = f;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите количество массива: ";
    cin >> n;

    int* a = new int[n];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Новый массив:" << endl;
    if (a[0] % 2 == 0)
        sdvig(a, n);
    else
        sdvig(a, n, true);

    print(a, n);

    delete[] a;

    return 0;
}