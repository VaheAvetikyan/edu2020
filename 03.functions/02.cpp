/*
    2: Անագրամ
    Գրել ծրագիր, որը մուտքում կստանա S1 և S2 բառերը (ոչ ավել քան 20 սիմվոլ) 
    և կարտածի ‘YES’, եթե մուտքագրված բառերը հանդիսանում են անագրամ և ‘NO’ հակառակ դեպքում: 
*/

#include <iostream>
#include <cstring>

int main()
{
    int length = 21;
    char string1[length];
    char string2[length];
    std::cin >> string1 >> string2;

    bool found = false;
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    if (len1 != len2)
    {
        std::cout << "NO\n";
        return 0;
    }

    int counter = 0;
    for (int i = 0; i < len1; i++)
    {
        counter = 0;
        for (int j = 0; j < len1; j++)
        {
            if (string1[i] == string1[j])
            {
                counter++;
            }
        }

        found = false;
        for (int j = 0; j < len2; j++)
        {
            if (string1[i] == string2[j])
            {
                counter--;
                if (counter == 0)
                {
                    found = true;
                }
                else
                {
                    found = false;
                }
            }
        }

        if (!found)
        {
            std::cout << "NO\n";
            return 0;
        }
    }

    if (found)
    {
        std::cout << "YES\n";
    }
}