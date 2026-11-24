#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

double side(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double cross(double ax, double ay, double bx, double by, double mx, double my) {
    return (bx - ax) * (my - ay) - (by - ay) * (mx - ax);
}

bool belong(double mx, double my,
    double x1, double y1,
    double x2, double y2,
    double x3, double y3) {
    const double EPS = 1e-9;

    double d1 = cross(x1, y1, x2, y2, mx, my);
    double d2 = cross(x2, y2, x3, y3, mx, my);
    double d3 = cross(x3, y3, x1, y1, mx, my);

    bool hasNeg = (d1 < -EPS) || (d2 < -EPS) || (d3 < -EPS);
    bool hasPos = (d1 > EPS) || (d2 > EPS) || (d3 > EPS);

    return !(hasNeg && hasPos);
}

bool belong(int n, double mx, double my, ...) {
    if (n < 3) return false;

    va_list args;
    va_start(args, my);

    double x1 = va_arg(args, double);
    double y1 = va_arg(args, double);

    double prevX = va_arg(args, double);
    double prevY = va_arg(args, double);

    bool isInside = false;

    for (int i = 2; i < n; ++i) {
        double currX = va_arg(args, double);
        double currY = va_arg(args, double);

        if (belong(mx, my, x1, y1, prevX, prevY, currX, currY)) {
            isInside = true;
            break;
        }

        prevX = currX;
        prevY = currY;
    }

    va_end(args);
    return isInside;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Тест 1 (Треугольник, точка (1,1)):  "
        << (belong(3, 1.0, 1.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0) ? "Принадлежит" : "Не принадлежит")
        << endl;

    cout << "Тест 2 (Квадрат, точка (4,2)):      "
        << (belong(4, 4.0, 2.0, 0.0, 0.0, 4.0, 0.0, 4.0, 4.0, 0.0, 4.0) ? "Принадлежит" : "Не принадлежит")
        << endl;

    cout << "Тест 3 (Пятиугольник, точка (6,6)): "
        << (belong(5, 6.0, 6.0, 1.0, 0.0, 4.0, 0.0, 5.0, 3.0, 2.5, 5.0, 0.0, 3.0) ? "Принадлежит" : "Не принадлежит")
        << endl;

    return 0;
}
