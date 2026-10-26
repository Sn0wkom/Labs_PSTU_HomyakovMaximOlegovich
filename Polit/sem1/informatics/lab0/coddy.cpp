#include <iostream>
#include <vector>
#include <string>

int main()
{
    setlocale(LC_ALL, "RU");

    int n, l, q, n1, l1;
    q = 0;

    std::cout << "Введите сколько будет элементов: ";
    std::cin >> n;
    std::vector<int> ar(n);
    std::cout << "Введите любую последовательность из нулей и единичек: ";
    for (int i = 0; i < n; i++)
        std::cin >> ar[i];
    std::cout << std::endl;

    std::cout << "Введите сколько будет элементов: ";
    std::cin >> n1;
    std::vector<std::string> arr(n1 + 2, "_");
    std::cout << "Введите любую последовательность из нулей и единичек: ";
    for (int i = 0; i < n1 + 1; i++)
        std::cin >> arr[i];
    std::cout << std::endl;

    std::cout << "Введите сколько будет элементов: ";
    std::cin >> l;
    std::vector<std::string> br(l + 2, "_");
    std::cout << "Введите любую последовательность из a и b: ";
    for (int i = 1; i < l + 1; i++)
        std::cin >> br[i];
    std::cout << std::endl;

    std::cout << "Введите сколько будет элементов: ";
    std::cin >> l1;
    std::vector<std::string> brr(l1 + 2, "_");
    std::cout << "Введите любую последовательность из a и b: ";
    for (int i = 1; i < l1 + 1; i++)
        std::cin >> brr[i];
    std::cout << std::endl;

    for (int i = 0; i < n; i++) // Первое задание
        if (ar[i] == 0)
            ar[i] = 1;
        else
            ar[i] = 0;

    for (int i = 0; i != n1 + 2;) // Второе задание
    {
        if (i < 0 || i >= n1 + 2)
            break;

        if (q == 0)
        {
            if (arr[i] == "_")
                break;
            else if (arr[i] == "1")
                i++;
            else if (arr[i] == "0")
                i++;
            else if (arr[i] == "+")
            {
                q = 1;
                i++;
            }
        }
        else if (q == 1)
        {
            if (arr[i] == "_")
                i--;
            else if (arr[i] == "1")
            {
                arr[i] = "+";
                q = 2;
                i--;
            }
            else if (arr[i] == "0")
            {
                arr[i] = "+";
                q = 3;
                i--;
            }
            else if (arr[i] == "+")
            {
                arr[i] = "_";
                q = 0;
                i++;
            }
        }
        else if (q == 2)
        {
            if (arr[i] == "+")
            {
                q = 0;
                arr[i] = "1";
                i++;
            }
        }
        else if (q == 3)
        {
            if (arr[i] == "+")
            {
                q = 0;
                arr[i] = "0";
                i++;
            }
        }
    }
    q = 0;

    for (int i = 1; i < l + 2;) // Третье задание
    {
        if (i < 0 || i >= l + 2)
            break;

        if (q == 0)
        {
            if (br[i] == "_")
            {
                q = 1;
                i--;
            }
            else if (br[i] == "a")
                i++;
            else if (br[i] == "b")
                i++;
        }
        else if (q == 1)
        {
            if (br[i] == "a")
            {
                br[i] = "_";
                q = 2;
                i--;
            }
            else if (br[i] == "b")
            {
                br[i] = "_";
                q = 3;
                i--;
            }
        }
        else if (q == 2)
        {
            if (br[i] == "_")
            {
                br[i] = "a";
                break;
            }
            else if (br[i] == "a")
                i--;
            else if (br[i] == "b")
                i--;
        }
        else if (q == 3)
        {
            if (br[i] == "_")
            {
                br[i] = "b";
                break;
            }
            else if (br[i] == "a")
                i--;
            else if (br[i] == "b")
                i--;
        }
    }
    q = 0;

    std::cout << "1) ";
    for (int i = 0; i < n; i++)
        std::cout << ar[i] << " ";
    std::cout << std::endl;

    std::cout << "2) ";
    for (int i = 0; i < n1; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::cout << "3) ";
    for (int i = 0; i < l; i++)
        std::cout << br[i] << " ";
    std::cout << std::endl;

    std::cout << "4) ";
    for (int i = 1; i < l1 + 2;) // Четвёртое задание
    {
        if (q == 0)
        {
            if (brr[i] == "_")
            {
                std::cout << "TRUE";
                break;
            }
            else if (brr[i] == "a")
            {
                q = 1;
                i++;
            }
            else if (brr[i] == "b")
            {
                q = 2;
                i++;
            }
        }
        else if (q == 1)
        {
            if (brr[i] == "_")
            {
                q = 3;
                i--;
            }
            else if (brr[i] == "a")
                i++;
            else if (brr[i] == "b")
                i++;
        }
        else if (q == 2)
        {
            if (brr[i] == "_")
            {
                q = 4;
                i--;
            }
            else if (brr[i] == "a")
                i++;
            else if (brr[i] == "b")
                i++;
        }
        else if (q == 3)
        {
            if (brr[i] == "a")
            {
                q = 5;
                brr[i] = "_";
                i--;
            }
            else
            {
                std::cout << "False";
                break;
            }
        }
        else if (q == 4)
        {
            if (brr[i] == "b")
            {
                q = 5;
                brr[i] = "_";
                i--;
            }
            else
            {
                std::cout << "False";
                break;
            }
        }
        else if (q == 5)
        {
            if (brr[i] == "_")
            {
                q = 6;
                i++;
            }
            else
            {
                i--;
            }
        }
        else if (q == 6)
        {
            if (brr[i] == "_")
            {
                std::cout << "True";
                break;
            }
            else if (brr[i] == "a")
            {
                q = 0;
                brr[i] = "_";
                i++;
            }
            else if (brr[i] == "b")
            {
                q = 0;
                brr[i] = "_";
                i++;
            }
        }
    }

    return 0;
}