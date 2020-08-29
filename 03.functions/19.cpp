/*
    19: Պայմանով արտահայտություն
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա A և B ամբողջ թվերը և Օ սիմվոլը, 
    որը կարող է լինել ‘+’, ‘-‘, ‘*’, ‘/’ կամ ‘%’: 
    Ծրագիրը պետք է արտածի O գործողության արդյունքը՝ կիրառված A և B թվերի նկատմամաբ։ 
    Անհրաժեշտ է յուրաքանչյուր գործողության համար ստեղծել առանձին ֆունկցիա։
*/

#include <iostream>

int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
int modula(int a, int b);

int main()
{
    int A, B;
    char symbol;
    std::cin >> A >> B;
    std::cin >> symbol;

    switch (symbol)
    {
    case '+':
        std::cout << addition(A, B) << "\n";
        break;
    case '-':
        std::cout << subtraction(A, B) << "\n";
        break;
    case '*':
        std::cout << multiplication(A, B) << "\n";
        break;
    case '/':
        std::cout << division(A, B) << "\n";
        break;
    case '%':
        std::cout << modula(A, B);
        break;
    }
}

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}

int modula(int a, int b)
{
    return a % b;
}