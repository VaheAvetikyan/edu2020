/*
    4: Սեղանի մակերես
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա ուղղանկյուն սեղանի հիմքերը ու բարձրությունը և կհաշվի այդ սեղանի մակերեսը։ 
*/

#include <iostream>

int main()
{
    double a, b, h;
    std::cin >> a >> b >> h;
    std::cout << h * (a + b) / 2 << std::endl;
}