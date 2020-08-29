/*
    7: Տարբերություն
    Գրել ծրագիր, որը մուտքում ստանում է N բնական թիվ, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Որպես արդյունք ծրագիրը պետք է արտածի հաջորականության մեծագույն և փոքրագույն տարրերի տարբերութունը։ 
    Արգելվում է օգտագործել զանգված։
*/

#include <iostream>
#include <limits.h>

int main()
{
    int N;
    std::cin >> N;

    int min = INT_MAX;
    int max = INT_MIN;

    int i = 0;
    while (i < N)
    {
        int input;
        std::cin >> input;

        if (input < min)
        {
            min = input;
        }

        if (input > max)
        {
            max = input;
        }

        i++;
    }

    std::cout << max - min << "\n";
}