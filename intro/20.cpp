/*
    20: Հակադիր թվեր
    Գրել ծրագիր, որը մուտքում կստանա A, B, C և D ամբողջ թվերը։ 
    Պահանջվում է արտածել YES եթե A-ն հակադիր է D֊ին և B֊ն հակադիր չէ C ֊ին, NO հակառակ դեպքում։
*/

#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a + d == 0 && b + c != 0)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
}