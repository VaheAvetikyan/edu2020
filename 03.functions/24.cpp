/*
    24: Ռեկուրենտ հաջորդականություն
    Տրված է Kn ռեկուրենտ հաջորդականություն, որի Ki տարրը որշվում է հետևյալ կանոններով․

    Ki = i, եթե i ≤ 3
    Ki = 2 * Ki + 3, եթե i-ն կենտ է և i > 3
    Ki = 3 + Ki / 2, եթե i-ն զույգ է և i > 3
    Գրել ծրագիր որը մուտքում կստանա i (i ≤ 1000000000) բնական թիվը և կարտածի հաջորդականության i֊րդ տարրը: 
*/

#include <iostream>

int recurrentK(int i);

int main()
{
    int n;
    std::cin >> n;
    std::cout << recurrentK(n) << "\n";
}

int recurrentK(int i)
{
    if (i <= 3)
        return i;
    if (i > 3 && i % 2 != 0)
        return 2 * recurrentK(i + 3);
    // if (i > 3 && i % 2 == 0)
    return 3 + recurrentK(i / 2);
}