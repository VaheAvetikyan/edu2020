/*
    4: Ենթաբառ
    Գրել ծրագիր, որը մուտքում կստանա մեկ բառ (ոչ ավել քան 20 սիմվոլ պարունակող) և մեկ սիմվոլ։ 
    Անհրաժեշտ է արտածել մուտքագրված բառում՝ տրված սիմվոլի առաջին հանդիպման դիրքից աջ ընկած ենթաբառը։
*/

#include <iostream>

int main()
{
    char string[21];
    char symbol;
    std::cin >> string >> symbol;

    int i = 0;
    while (string[i])
    {
        if (string[i] == symbol)
        {
            i++;
            break;
        }
        i++;
    }

    while (string[i])
    {
        std::cout << string[i];
        i++;
    }
    std::cout << "\n";
}