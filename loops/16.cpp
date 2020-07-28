/*
    16: Պարզ թվերի քանակ
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա n (n ≤ 100) բնական թիվ, 
    ապա a0, a1, a2, ... an-1 ամբողջ թվերի հաջորդականությունը և կարտածի b0, b1, b2, ... bn-1։ 
    Որտեղ bi -ն ai -ից փոքր պարզ թվերի քանակն է։ 
    Արտածվող թվերը միմյանցից պետք է բաժանված լինեն բացատանիշով։ 
    Խնդիրը լուծելիս օգտագործել զանգված։ 
*/

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int a[n];
    int b[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int number = 2;
        while (number < a[i])
        {
            bool prime = true;
            int divisor = 2;
            while (divisor < number)
            {
                if (number % divisor == 0)
                {
                    prime = false;
                    break;
                }
                divisor++;
            }

            if (prime)
            {
                count++;
            }
            number++;
        }

        b[i] = count;
        count = 0;
        std::cout << b[i] << " ";
    }

    std::cout << "\n";
}