/*
    16: Փոքր ASCII կոդ
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա 2 սիմվոլ ASCII աղյուսակից և 
    կարտածի YES, եթե երկրորդ սիմվոլն ունի ավելի փոքր ASCII կոդ քան առաջինը և NO հակառակ դեպքում։ 
    Նույն սիմվոլների դեպքում արտածել EQUAL:
*/

#include <iostream>

int main()
{
    char a, b;
    std::cin >> a >> b;

    if (b < a)
    {
        std::cout << "YES";
    }
    else if (a < b)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "EQUAL";
    }

    std::cout << "\n";
}