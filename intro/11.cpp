/*
    11: Հավասարություն
    Գրել ծրագիր, որը մուտքում կստանա 2 դրական ամբողջ թիվ և կարտածի YES, եթե այդ թվերը հավասար են և NO հակառակ դեպքում։
*/

#include <iostream>

int main()
{
    unsigned int a, b;
    std::cin >> a >> b;

    if (a == b)
        std::cout << "YES";
    else
        std::cout << "NO";
}