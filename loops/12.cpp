/*
    12: Նախ թվանշանները
    Գրել ծրագիր, որը մուտքում ստանում է N (N ≤ 1000) բնական թիվ, ապա հաջորդականություն N սիմվոլներից կազմված։ 
    Որպես արդյունք ծրագիրը պետք է արտածի հաջորդականության թվանշանները ապա մնացած սիմվոլները։ 
    Արտածվող սիմվոլները միմյանցից պետք է բաժանված լինեն բացատանիշով։ 
    Խնդիրը լուծելիս օգտագործել զանգված։
*/

#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    char array[N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> array[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (array[i] >= '0' && array[i] <= '9')
        {
            std::cout << array[i] << " ";
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (array[i] < '0' || array[i] > '9')
        {
            std::cout << array[i] << " ";
        }
    }

    std::cout << std::endl;
}
