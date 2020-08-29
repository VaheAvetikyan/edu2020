#include <iostream>

bool isPrime(int number);

int main()
{
    int input;
    std::cin >> input;

    if (isPrime(input))
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
}

bool isPrime(int number)
{
    if (number < 2)
        return false;

    int divisor = 2;
    while (divisor < number)
    {
        if (number % divisor == 0)
        {
            return false;
        }
        divisor++;
    }
    return true;
}