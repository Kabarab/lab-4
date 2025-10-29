#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;

template <typename T>
T get_value( const string& error_message)
{
    T value;
    while (!(cin >> value))
    {
        cout << error_message << "\n";
        cout << "Введите значение снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

long double Yx (long double x){
    long double ans = cos(x);
    return ans;

}


long double Sx(long double x, int n)
{
    if (n <= 0) {
        return 0;
    }
    long double sx = 1;
    long double term = 1;

    for (int k = 1; k <= n; ++k) {
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
        cout << "|" <<setw(15) << fixed << setprecision(15) << ans <<setw(15) << "|\n";
    }
}

int main() {
    long double a, b, h, yx;
    int n, choice;
    cout << "Введите верхний предел n: ";
    n = get_value<int>("Значение должно быть целым числом\n");
    cout << "Введите начальное значение диапазона (a): ";
    a = get_value<long double>("Значение должно быть числом\n");
    cout << "Введите конечное значение диапазона (b): ";
    b = get_value<long double>("Значение должно быть числом\n");
    cout << "Введите шаг интервала (h): ";
    h = get_value<long double>("Значение должно быть числом\n");

    while (true) {
        cout << "\n| 1-Вывести x | 2-Вывести S(x) | 3-Вывести Y(x) | 4-Вывести погрешность | 5-Завершить программу |\n"
             << "Ваш выбор: ";
        choice = get_value<int>("Значение должно быть целым числом\n");

        switch (choice)
        {
        case 1:
            cout << "| " << setw(15) << "x" << setw(15) <<" |\n";
            for (long double x = a; x <= b; x += h)
            {
                cout << "| " << setw(15) << fixed << setprecision(3) << x << setw(15) << " |\n";
            }
            cout << "-------------------------------\n";
            break;
        case 2:
            cout << "| "<< setw(16) << "S(x)"<< setw(15) <<" |\n";
            Out_Rez(Sx, a, b, h, n);
            cout << "--------------------------------\n";
            break;
        case 3:
            cout << "| "<< setw(14) << "Y(x)" << setw(14) <<" |\n";
            for (long double x = a; x <= b; x += h)
            {
                yx = Yx(x);
                cout << "| " << setw(14) << fixed << setprecision(5)<< yx << setw(15) << "| \n";
            }
            cout << "-----------------------------\n";
            break;
        case 4:
            cout << "| "<< setw(15) <<" |Y(x)-S(x)| "<< setw(16) <<" |\n";
            Out_Rez(Difference, a, b, h, n);
            cout << "--------------------------------\n";
            break;
        case 5:
            return 0;
        default:
            cout << "Такого выбора не было, выберите снова!\n";
            break;
        }
    }
}