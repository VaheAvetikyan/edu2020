/*
    20: Insertion sort
    Պահանջվում է գրել ծրագիր, որը մուտքում ստանում է N (N ≤ 1000) բնական թիվ, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Անհրաժեշտ է, որ ծրագիրը արտածի հաջորդականության տարրերը դասավորված նվազման կարգով։ 
    Արտածվող թվերը միմյանցից պետք է բաժանված լինեն բացատանիշով։ 
    Խնդիրը լուծելիս օգտագործել զանգված և insertion sort ալգորիթմ։ 
*/

#include <iostream>
#include <limits.h>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int key;
    int j;

    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}