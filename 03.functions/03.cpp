/*
    3: Պալինդրոմ
    Գրել ծրագիր, որը մուտքում կստանա բառ (ոչ ավել քան 20 սիմվոլ) 
    և կարտածի ‘YES’, եթե մուտքագրված բառը պալինդրոմ է և ‘NO’ հակառակ դեպքում:
*/

#include <iostream>
#include <cstring>

int main()
{
    char string[21];
    std::cin >> string;
    int len = strlen(string);
    bool isPalindrome = true;
    for (int i = 0; i < len / 2; i++)
    {
        if (string[i] != string[len - i - 1])
        {
            isPalindrome = false;
        }
    }

    if (isPalindrome)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
}