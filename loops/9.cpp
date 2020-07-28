/*
    9: Մաքսիմալի հաճախակիություն
    Գրել ծրագիր, որը մուտքում ստանում է N ոչ բացասական ամբողջ թիվ, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Որպես արդյունք ծրագիրը պետք է արտածի հաջորդականությունում մաքսիմալ տարրի հանդիպելու քանակը։ 
    Արգելվում է օգտագործել զանգված։ 
*/

#include <iostream>
#include <limits.h>

int main()
{
    unsigned int N;
    std::cin >> N;

    int max = INT_MIN;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        int input;
        std::cin >> input;

        if (input > max)
        {
            max = input;
            count = 1;
        }
        else if (input == max)
        {
            count++;
        }
    }

    std::cout << count << "\n";
}
