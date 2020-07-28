/*
    12: Երկուսից մեծը
    Գրել ծրագիր, որը մուտքում կստանա 2 դրական ամբողջ թիվ և կարտածի այդ թվերց մեծը։ 
*/

#include <iostream>

int main()
{
    long a, b;
    std::cin >> a >> b;

    if (a > b)
        std::cout << a;
    else
        std::cout << b;
}