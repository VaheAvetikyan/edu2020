/*
    4: Պարզ թվեր
    Գրել ծրագիր, որը մուտքում կստանա դրական թիվ և կարտածի մինչև այդ թիվը եղած բոլոր պարզ թվերը։ 
    Արտածվող թվերը միմյանցից պետք է բաժանված լինեն բացատանիշով։
*/

#include <iostream>

int main()
{
    int input;
    std::cin >> input;

    int number = 2;
    while (number <= input)
    {
        bool prime = true;
        int divisor = 2;
        while (divisor < number)
        {
            if (number % divisor == 0)
            {
                prime = false;
                break;
            }
            divisor++;
        }

        if (prime)
        {
            std::cout << number << " ";
        }
        number++;
    }
    std::cout << "\n";
}