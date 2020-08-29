/*
    23: Չեբիշևի բազմանդամ
    Գրել ծրագիր որը մուտքում տրված n ≥ 0 ամբողջ և x իրական թվերի համար գտնում է Չեբիշևի բազմանդամի n-րդ գործակիցը։ 
    Չեբիշևի Tn(x) բազմանդամը սահմանվում է հետևյալ ձևով. (դաս 12)

    T0(x) = 1
    T1(x) = x
    Tn(x) = 2 * x * Tn-1(x) - Tn-2(x), n = 2, 3, ...
*/

#include <iostream>
#include <iomanip>

// Function declaration
double chebishyev(int n, double x);

int main()
{
    int n;
    double x;
    std::cin >> n >> x;
    std::cout << std::fixed << chebishyev(n, x) << "\n";
}

double chebishyev(int n, double x)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    return 2 * x * chebishyev(n - 1, x) - chebishyev(n - 2, x);
}