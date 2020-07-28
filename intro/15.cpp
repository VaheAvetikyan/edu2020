/*
    15: Մեծությամբ երկրորդը
    Գրել ծրագիր, որը մուտքում կստանա 3 ամբողջ թիվ և կարտածի այդ թվերից մեծությամբ երկրորդը։ 
*/

#include <iostream>

int main()
{
    long a, b, c;
    std::cin >> a >> b >> c;

    if (a > b && a < c || a > c && a < b)
        std::cout << a;
    else if (b > a && b < c || b > c && b < a)
        std::cout << b;
    else
        std::cout << c;

    std::cout << "\n";
}