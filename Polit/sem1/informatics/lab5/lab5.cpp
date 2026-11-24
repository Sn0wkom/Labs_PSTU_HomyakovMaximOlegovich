#include <iostream>
#include <iomanip>

using namespace std;

void techmat(const int* a, int** a2, int n)
{
    if (n == 1)
    {
        a2[0][0] = a[0];
        return;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n; j++)
            a2[i][j] = 1;

    for (int j = 0; j < n; j++)
    {
        int last = a[j] - (n - 1);

        if (last == 0)
        {
            a2[n - 2][j] = 2;
            a2[n - 1][j] = -1;
        }
        else 
            a2[n - 1][j] = last;
    }

}

void print(int** a2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a2[i][j];
        cout << endl;
    }


}

int main()
{
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите количство массива: ";
    cin >> n;

    int* a = new int[n];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int** a2 = new int* [n];
    for (int i = 0; i < n; ++i) 
        a2[i] = new int[n];
    
    techmat(a, a2, n);

    cout << "Новая матрица:" << endl;
    print(a2, n);

    delete[] a;
    for (int i = 0; i < n; ++i)
        delete[] a2[i];
    delete[] a2;

    return 0;
}