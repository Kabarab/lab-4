#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;



double get_double_value()
{
    double value;
    while (!(cin >> value))
    {
        cout << "Некорректное значение. Пожалуйста, введите число." << endl;
        cout << "Введите значение снова: " << endl;

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}
int get_int_value()
{
    int value;
    while (!(cin >> value))
    {
        cout << "Некорректное значение." << endl;
        cout << "Значение должно быть целым числом." << endl;
        cout << "Введите значение снова:" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}

string vivod(long double number, int n) {
    stringstream ss;
    ss << setprecision(20) << number;
    string vivod_str = ss.str();

    if (vivod_str.length() >= n) {
        return vivod_str.substr(0, n);
    }

    while (vivod_str.length() < n) {
        vivod_str += ' ';
    }

    return vivod_str;
}
long double Yx (long double x){
    long double ans=cos(x);
    return ans;

}


long double Sx(long double x, int n)
{
    if (n <= 0) {
        return 0;
    }
    long double sx = 1;
    long double term = 1;

    for (int k = 1; k < n; ++k) {
        term = term * (-1) * x * x / ((2 * k - 1) * (2 * k));
        sx += term;
    }

    return sx;
}

long double Difference(long double x, int n) {
    long double s = Sx(x, n);
    long double y = Yx(x);
    return fabs(s - y);
}

void Out_Rez(long double func(long double, int), long double a, long double b, long double h, int n)
{
    for (long double x = a; x <= b; x += h)
    {
        long double ans = func(x, n);
        cout << "|     " << vivod(ans, 20) << "     |" << endl;
    }
}

int main() {
    long double a, b, h, yx;
    int n, choice;
    cout << "Введите верхний предел n: ";
    n = get_int_value();
    cout << "Введите начальное значение диапазона (a): ";
    a = get_double_value();
    cout << "Введите конечное значение диапазона (b): ";
    b = get_double_value();
    cout << "Введите шаг интервала (h): ";
    h = get_double_value();

    while (true) {
        cout << "\n| 1-Вывести x | 2-Вывести S(x) | 3-Вывести Y(x) | 4-Вывести погрешность | 5-Завершить программу |" << endl
             << "Ваш выбор: ";
        choice = get_int_value();

        switch (choice)
        {
        case 1:
            cout << "--------------------------------" << endl
                 << "|                x             |" << endl
                 << "+------------------------------+" << endl;
            for (long double x = a; x <= b; x += h)
            {
                cout << "|      " << vivod(x, 20) << "    |" << endl;
            }
            cout << "--------------------------------" << endl;
            break;
        case 2:
            cout << "--------------------------------" << endl
                 << "|               S(x)           |" << endl
                 << "+------------------------------+" << endl;
            Out_Rez(Sx, a, b, h, n);
            cout << "--------------------------------" << endl;
            break;
        case 3:
            cout << "--------------------------------" << endl
                 << "|               Y(x)           |" << endl
                 << "+------------------------------+" << endl;
            for (long double x = a; x <= b; x += h)
            {
                yx = cos(x);
                cout << "|      " << vivod(yx, 20) << "    |" << endl;
            }
            cout << "--------------------------------" << endl;
            break;
        case 4:
            cout << "--------------------------------" << endl
                 << "|           |Y(x)-S(x)|        |" << endl
                 << "+------------------------------+" << endl;
            Out_Rez(Difference, a, b, h, n);
            cout << "--------------------------------" << endl;
            break;
        case 5:
            return 0;
        default:
            cout << "Такого выбора не было, выберите снова!" << endl;
            break;
        }
    }
}