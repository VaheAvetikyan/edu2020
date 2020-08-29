/*
    3: Մնացորդ
    Գրել ծրագիր, որը մուտքում կստանա A և B դրական ամբողջ թվերը և կարտածի A֊ն B֊ի բաժանման արդյունքում ստացված մնացորդը։ 
    Հայտնի է, որ B֊ն 0 չէ։ 
*/

#include <iostream>

int main()
{
    unsigned int A, B;
    std::cin >> A >> B;
    std::cout << A % B << std::endl;
}