/*
    20: Եռանկյան մակերես
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա եռանկյան 3 կողմերը և կարտածի դրա մակերեսը։ 
    Խնդիրը լուծելու համար օգտվել Հերոնի բանաձևից և sqrt() ֆունկցիայից։ 
    Մակերեսը հաշվելու համար անհրաժեշտ է օգտագործել ֆունկցիա։
*/

#include <iostream>
#include <cmath>

double halfPerimeter(double a, double b, double c);
double heronFormula(double a, double b, double c);

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    std::cout << heronFormula(a, b, c) << "\n";
}

double halfPerimeter(double a, double b, double c)
{
    return (double)(a + b + c) / 2;
}

double heronFormula(double a, double b, double c)
{
    double p = halfPerimeter(a, b, c);
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    return S;
}