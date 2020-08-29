/*
    13: Երեքից փոքրը
    Գրել ծրագիր, որը մուտքում կստանա 3 ամբողջ թիվ և կարտածի այդ թվերից փոքրը։ 
*/

#include <iostream>

int main()
{
    long a, b, c;
    std::cin >> a >> b >> c;

    if (a < b && a < c)
        std::cout << a;
    else if (b < a && b < c)
        std::cout << b;
    else
        std::cout << c;
}