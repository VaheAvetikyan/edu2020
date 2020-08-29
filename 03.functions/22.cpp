/*
    22: Ամենամեծ ընդհանուր բաժանարար
    Գրել ծրագիր, որը մուտքում կստանա երկու բնական թվեր և կարտածի դրանց ամենամեծ ընդհանուր բաժանարարը: 
    Անհրաժեշտ է խնդիրը լուծել ռեկուրսիվ ֆունկցիայի միջոցով։
*/

#include <iostream>

// Function declaration
int greatestCommonDivisor(int a, int b);

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << greatestCommonDivisor(a, b) << "\n";
}

int greatestCommonDivisor(int a, int b)
{
    if (b == 0)
        return a;
    return greatestCommonDivisor(b, a % b);
}