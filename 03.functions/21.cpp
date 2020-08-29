/*
    21: Ֆակտորիալ և ֆիբոնաչի
    Գրել ծրագիր, որը մուտքում կստանա n (1 ≤ n ≤ 10) և 
    կարտածի մուտքային թվի ֆակտորիալի և ֆիբոնաչիի հաջորդականության n֊րդ տարրի հարաբերությունը 5 նիշի ճշտությամբ: 
    Անհրաժեշտ է, որ թվի ֆակտորիալ հաշվելու և ֆիբոնաչիի հաջորդականության n֊րդ տարրի հաշվարկի ֆունկցիաները լինեն ռեկուրսիվ:
*/

#include <iostream>
#include <iomanip>

int factorial(int n);
int fibonacci(int n);

int main()
{
    int n;
    std::cin >> n;
    double fact = factorial(n);
    double fib = fibonacci(n);
    double result = fact / fib;
    std::cout << std::fixed << result << "\n";
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (fibonacci(n - 1) + fibonacci(n - 2));
}