/*
    9: Տարրի կրկնությունների քանակ
    Գրել ծրագիր, որը մուտքում կստանա N բնական թիվ, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Պահանջվում է արտածել հաջորդականության յուրաքանչյուր տարրի կրկնությունների քանակը։
*/

#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int *sequence = new int[num];
    int *recurrence = new int[num];

    for (int i = 0; i < num; i++)
    {
        std::cin >> sequence[i];
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (sequence[i] == sequence[j])
            {
                recurrence[i]++;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        std::cout << recurrence[i] << " ";
    }
    std::cout << "\n";
}