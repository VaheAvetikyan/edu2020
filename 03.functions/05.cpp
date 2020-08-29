/*
    5: Ենթաբառ ֊ 2
    Գրել ծրագիր, որը մուտքում կստանա S1 բառը (ոչ ավել քան 20 սիմվոլ), 
    S2 բառը (ոչ ավել քան S1 բառում սիմվոլների քանակը) 
    և կարտածի ‘YES’, եթե S2 հանդիսանում է ենթաբառ S1֊ից և ‘NO’ հակառակ դեպքում: 
*/

#include <iostream>
#include <cstring>

int main()
{
    char string1[21];
    std::cin >> string1;
    int len_1 = strlen(string1);

    char string2[len_1];
    std::cin >> string2;
    int len_2 = strlen(string2);

    bool isSubstring = false;
    for (int i = 0; i < len_1; i++)
    {
        if (string1[i] == string2[0])
        {
            isSubstring = true;
            for (int j = 1; j < len_2; j++)
            {
                if (string1[i + j] != string2[j])
                {
                    isSubstring = false;
                    break;
                }
            }
            if (isSubstring)
            {
                std::cout << "YES\n";
                break;
            }
        }
    }

    if (!isSubstring)
    {
        std::cout << "NO\n";
    }
}