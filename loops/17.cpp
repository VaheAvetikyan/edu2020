/*
    17: Չի կրկնվում միայն
    Պահանջվում է գրել ծրագիր, որը մուտքում ստանում է N (N ≤ 100) բնական թիվ, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Հայտնի է, որ հաջորդականության բոլոր տարրերը հանդիպում են ճիշտ երկու անգամ բացառությամբ մեկի։ 
    Պահանջվում է արտածել մեկ անգամ հանդիպող տարրը և կարգահամարը հաջորդականությունում։ 
    Խնդիրը լուծելիս օգտագործել զանգված։ 
*/

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool repeat = false;
        for (int j = 0; j < n; j++)
        {
            if (i != j && a[i] == a[j])
            {
                repeat = true;
                break;
            }
        }

        if (!repeat)
        {
            std::cout << a[i] << " " << i << "\n";
        }
    }
}