/*
    1: 10֊ից մեծ
    Գրել ծրագիր, որը մուտքում կստանա դրական թիվ և կարտածի 10-ից միչև այդ թիվը եղած բոլոր ամբողջ թվերը։ 
    Հայտնի է որ մուտքային թիվը փոքր չէ 10-ից։ 
    Արտածվող թվերը միմյանցից պետք է բաժանված լինեն բացատանիշով։ 
*/

#include <iostream>

int main()
{
    int i;
    std::cin >> i;
    int j = 10;

    while (j <= i)
    {
        std::cout << j << " ";
        j++;
    }
    std::cout << std::endl;
}