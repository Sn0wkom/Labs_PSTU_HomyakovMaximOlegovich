#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x, a, b, SN, SE, y, k, d;
	a = -2;
	b = -0.1;
	x = -2;
	k = 10;
	d = 1;

	while (x <= b)
	{
		y = log(1 / (2 + 2 * x + pow(x, 2)));
		SN = 0;
		SE = 0;

		for (int n = 1; n <= 40; n++)
		{
			d *= -1 - 2 * x - x * x;
			SN +=  d / n;
		}
		
		for (int n = 1; (pow(-1, n) * pow((1 + x), 2 * n) / n) > 1e-4; n++)
		{
			SE += pow(-1, n) * pow((1 + x), 2 * n) / n;
		}

		cout << "X = " << x << " SN = " << SN << " SE = " << SE << " Y = " << y << endl;

		x += (b - a) / k;
	}
	return 0;
}