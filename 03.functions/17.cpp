/*
    17: Երկուական ներկայացում
    Գրել ծրագիր, որը մուտքում կստանա ոչ բացասական ամբողջ թիվ և կարտածի այդ թվի երկուական ներկայացումը։ 
    Տասականից երկուականի անցումը իրականացնել ֆունկցիայի միջոցով։ 
    Ֆունկցիան պետք է ընդունի int տիպի մեկ փոփոխական և վերադարձնի int տիպի արժեք։
*/

#include <iostream>

long binaryRepresentation(int number);

int main()
{
    int input;
    std::cin >> input;

    long binary = binaryRepresentation(input);

    std::cout << binary << "\n";
}

long binaryRepresentation(int number)
{
    long bin = 0;
    long i = 1;
    while (number > 0)
    {
        bin += i * (number % 2);
        number = number / 2;
        i = i * 10;
    }
    return bin;
}