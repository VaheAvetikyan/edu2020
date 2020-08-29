/*
    8: Ամենաերկար ենթահաջորդականություն
    Գրել ծրագիր, որը մուտքում կստանա N բնական թիվ, ապա N ամբողջ տարրերից կազմված հաջորդականություն։ 
    Պահանջվում է արտածել հաջորդականության ամենաերկար խիստ աճող հատվածի տարրերի քանակը։
*/

#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int *sequence = new int[num];

    for (int i = 0; i < num; i++)
    {
        std::cin >> sequence[i];
    }

    int count = 1;
    int maxCount = 0;

    for (int i = 0; i < num; i++)
    {
        while (sequence[i + 1] > sequence[i] && i < num - 1)
        {
            count++;
            i++;
        }

        if (count > maxCount)
        {
            maxCount = count;
        }
        count = 1;
    }

    std::cout << maxCount << "\n";
}