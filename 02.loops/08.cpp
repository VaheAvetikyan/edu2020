/*
    8: Թոփ եռյակ
    Գրել ծրագիր, որը մուտքում ստանում է N (N ≥ 3) բնական թիվ, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Որպես արդյունք ծրագիրը պետք է արտածի հաջորդականության 3 ամենամեծ տարրերը։ 
    Տարրերը պետք է արտածել փոքրից մեծ և տարանջատել բացատանիշներով։ 
    Արգելվում է օգտագործել զանգված։
*/

#include <iostream>
#include <limits.h>

int main()
{
    int N;
    std::cin >> N;

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    int i = 0;
    while (i < N)
    {
        int input;
        std::cin >> input;

        if (input > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = input;
        }
        else if (input > max2)
        {
            max3 = max2;
            max2 = input;
        }
        else if (input > max3)
        {
            max3 = input;
        }

        i++;
    }
    std::cout << max3 << " " << max2 << " " << max1 << "\n";
}