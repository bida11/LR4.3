// Біда О. М., ІК-12. ЛР 4.3, варіант 1. Параметри a, b, c.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, xp, xk, dx;
    cout << "a, b, c, xp, xk, dx: ";
    if (!(cin >> a >> b >> c >> xp >> xk >> dx)
        || !isfinite(a) || !isfinite(b) || !isfinite(c)
        || !isfinite(xp) || !isfinite(xk) || !isfinite(dx)
        || dx <= 0 || xp > xk || (xk - xp) / dx > 1000000) {
        cerr << "Invalid input\n"; return 1;
    }
    const int m = int(floor((xk - xp) / dx + 1e-10));
    cout << "TABLE F(x)\n" << setw(12) << "x"
        << setw(22) << "F" << '\n';
    cout << fixed << setprecision(6);
    for (int j = 0; j <= m; ++j) {
        const double x = xp + j * dx;
        double F = 0;
        bool defined = true;
        if (x < 0 && b != 0) F = a * x * x + b;
        else if (x > 0 && b == 0) {
            if (x == c) defined = false;
            else F = (x - a) / (x - c);
        }
        else {
            if (c == 0) defined = false;
            else F = x / c;
        }
        cout << setw(12) << x;
        if (defined && isfinite(F)) cout << setw(22) << F;
        else cout << setw(22) << "undefined";
        cout << '\n';
    }
}
