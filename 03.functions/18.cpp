/*
    18: Արտահայտության արժեք
    Գրել ֆունկցիա, որը որպես արգումենտ կստանա n բնական թիվը և կվերադարձնի n!/(n+1) արտահայտության արժեքը։ 
    Ապա, օգտվելով վերոնշյալ ֆունկցիայից, հաշվել հետևյալ արտահայտության արժեքը 
    1!/2 + 2!/3 + 3!/4 + 4!/5 + 5!/6 + 6!/7 + 7!/8 + 8!/9 + 9!/10 + 10!/11: 
    Պատասխանը արտածել 5 նշի ճշտությամբ։
*/

#include <iostream>
#include <iomanip>

int factorial(int n);
double factOverNum(int num);

int main()
{
    double result = 0;
    for (int i = 1; i < 11; i++)
    {
        result += factOverNum(i);
    }
    std::cout << std::fixed << result << "\n";
}

int factorial(int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        n *= i;
    }
    return n;
}

double factOverNum(int num)
{
    return (double)factorial(num) / (double)(num + 1);
}