#include <iostream>
#include <random>
#include <utility>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	const int n = 100;
	int i, k, b, j, h, ch;
	int a[n];

	cout << "введите количество элементов массива не большее 100 = ";
	cin >> b;

	if (b > 0 && b <= 100)
	{
		cout << "введите число с которого будет выведен кольцевой массив = ";
		cin >> k;

		
		h = k;
		k = k % b - 1;

		for (i = 0; i < b; i++)
			a[i] = rand();

		cout << "1) Простой массив: { ";
		for (i = 0; i < b; i++)
			 cout << a[i] << " ";
		cout << " }" << endl;

		cout << "2) Кольцевой массив начиная с " << h << " элемента = { ";
		for (i = 0; i < b; i++)
			cout << a[(i + k) % b] << " ";
		cout << " }" << endl;

		j = b - 1;
		cout << "3) Кольцевой массив по возрастанию = { ";
		do
		{
			for (i = 0; i < b - 1; i++)
				if (a[i] > a[i + 1])
					swap(a[i], a[i + 1]);
			j--;
		}
		while (j != 0);
		for (i = 0; i < b; i++)
			cout << a[i] << " ";
		cout << " }" << endl;

		cout << "4) Кольцевой массив без чётных элементов = { ";
		int w = 0;
		for (int i = 0; i < b; i++) {
			if (a[i] % 2 != 0) 
			{
				a[w] = a[i];
				w++;
			}
		}
		b = w;
		for (i = 0; i < b; i++)
			cout << a[(i + k) % b] << " ";
		cout << " }" << endl;

		cout << "5) Полученный кольцевой массив начиная с " << h << " элемента = { ";
		for (i = 0; i < b; i++)
			cout << a[(i + k) % b] << " ";
		cout << " }" << endl;
	}

	return 0;
}