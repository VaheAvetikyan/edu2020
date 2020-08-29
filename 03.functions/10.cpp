/*
    10: 0-ին մոտ
    Գրել ծրագիր, որը մուտքում կստանա N բնական թիվ, ապա N ամբողջ տարրերից կազմված հաջորդականություն։ 
    Պահանջվում է արտածել հաջորդականության այն երկու տարրերը, որոնց գումարն ամենամոտն է 0-֊ին։ 
    Այդպիսիք մի քանիսը լինելու դեպքում արտածել առաջինը։ 
    Թվի հեռավորությունը 0-ից կարող եք ստանալ՝օգտագործելով std::abs() հրամանը։
*/

#include <iostream>
#include <limits.h>

int main()
{
    int len;
    std::cin >> len;
    int *sequence = new int[len];

    for (int i = 0; i < len; i++)
    {
        std::cin >> sequence[i];
    }

    int absDistance = INT_MAX;
    int minDistanceToZero = INT_MAX;
    int index_1, index_2;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i != j)
            {
                absDistance = std::abs(sequence[i] + sequence[j]);
            }
            if (minDistanceToZero > absDistance)
            {
                minDistanceToZero = absDistance;
                index_1 = i;
                index_2 = j;
            }
        }
    }

    std::cout << sequence[index_1] << " " << sequence[index_2] << "\n";
}