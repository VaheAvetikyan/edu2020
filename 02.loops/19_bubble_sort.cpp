/*
    19: Bubble sort
    Պահանջվում է գրել ծրագիր, որը մուտքում ստանում է N (N ≤ 1000) բնական թիվ, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Անհրաժեշտ է, որ ծրագիրը արտածի հաջորդականության տարրերը դասավորված նվազման կարգով։ 
    Արտածվող թվերը միմյանցից պետք է բաժանված լինեն բացատանիշով։ 
    Խնդիրը լուծելիս օգտագործել զանգված և bubble sort ալգորիթմ։ 
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

    bool swap = true;
    for (int i = 0; i < n - 1; i++)
    {
        swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }

    std::cout << "\n";
}
