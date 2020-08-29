/*
    9: Փոքրատառ և մեծատառ
    Գրել ծրագիր, որը մուտքում ստանում է N թիվը [1, 26] միջակայքից և արտածում լատինական այբուբենի N-րդ փոքրատառն ու մեծատառը:
*/

#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    char c = 'A';
    char hi = c + N - 1;
    char lo = c + ('a' - 'A') + N - 1;
    std::cout << lo << " " << hi << std::endl;
}