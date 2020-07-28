/*
    18: Նվազման կարգ
    Գրել ծրագիր, որը մուտքում կստանա 4 ամբողջ թիվ և կարտածի YES, եթե բոլոր թվերը մուտքագրվել են նվազման կարգով և NO հակառակ դեպքում։
*/

#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a >= b && b >= c && c >= d)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    std::cout << "\n";
}