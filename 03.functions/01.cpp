/*
    1: Սիմվոլների քանակ
    Գրել ծրագիր, որը մուտքում կստանա բառ (ոչ ավել քան 20 սիմվոլ), և կարտածի մուտքագրված սիմվոլների քանակը։
*/

#include <iostream>

int main()
{
    char str[21];
    std::cin >> str;

    int i = 0;
    while (str[i])
    {
        i++;
    }
    std::cout << i << "\n";
}