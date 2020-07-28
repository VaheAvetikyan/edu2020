/*
    6: Ճիշտ K հատ
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա N և K ոչ բացասական ամբողջ թվերը, ապա հաջորդականություն N ամբողջ տարրերից կազմված։ 
    Ծրագիրը որպես արդյունք պետք է արտածի ՛YES՛ եթե N թվերից ճիշտ K հատը մեծ են կամ հավասար 123 ֊ից և ‘NO’ հակառակ դեպքում։ 
    Արգելվում է օգտագործել զանգված։
*/

#include <iostream>

int main()
{
    int N, K;
    std::cin >> N >> K;

    int count = 0;
    int i = 0;
    while (i < N)
    {
        int input;
        std::cin >> input;
        if (input >= 123)
        {
            count++;
        }
        i++;
    }

    if (count == K)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
}
