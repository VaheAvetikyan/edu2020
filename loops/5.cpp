/*
    5: Թվերի գումար
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա ամբողջ թիվ այնքան ժամանակ քանի դեռ չի ներմուծվել 0։ 
    Եվ կարտածի ներմուծված թվերի գումարը։ Արգելվում է օգտագործել զանգված։ 
*/

#include <iostream>

int main()
{
    int i;
    int sum = 0;
    while (true)
    {
        std::cin >> i;
        sum += i;
        if (i == 0)
        {
            break;
        }
    }

    std::cout << sum << std::endl;
}