/*
    18: Ամենամեծ բացասական թիվ
    Պահանջվում է գրել ծրագիր, որը մուտքում ստանում է n (n ≤ 1000) բնական թիվ, 
    ապա a1, a2, a3, ... an ամբողջ թվերի հաջորդականությունը և կարտածի ամենամեծ բացասական թիվը և դրա կարգահամարը, այդպիսին չլինելու դեպքում ՛0 -1՛։ 
    Խնդիրը լուծելիս օգտագործել զանգված։
*/

#include <iostream>
#include <limits.h>

int main()
{
    int n;
    std::cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int max = INT_MIN;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max && a[i] < 0)
        {
            max = a[i];
            index = i;
        }
    }

    if (max == INT_MIN)
    {
        max = 0;
        index = -1;
    }

    std::cout << max << " " << index << "\n";
}