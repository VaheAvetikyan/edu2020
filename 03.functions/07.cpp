/*
    7: Կրկնվող տարրեր
    Գրել ծրագիր, որը մուտքում կստանա N բնական թիվ, ապա N ամբողջ տարրերից կազմված հաջորդականություն ։ 
    Պահանջվում է արտածել հաջորդականության բոլոր այն տարրերը, որոնք կրկնվում են։ 
    Կրկնվող թվերը պետք է արտածվեն նույն հերթականությամբ ինչպես ներմուծվել էին և միմյանցից պետք է բաժանված լինեն բացատանիշով։ 
    Խնդիրը լուծելիս օգտագործել դինամիկ զանգված։
*/

#include <iostream>

int main()
{
    int len;
    std::cin >> len;
    int *dynArr = new int[len];
    bool *alreadySeen = new bool[len];

    for (int i = 0; i < len; i++)
    {
        std::cin >> dynArr[i];
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (dynArr[i] == dynArr[j] && !alreadySeen[i])
            {
                std::cout << dynArr[i] << " ";
                alreadySeen[i] = true;
                alreadySeen[j] = true;
            }
            else if (dynArr[i] == dynArr[j])
            {
                alreadySeen[j] = true;
            }
        }
    }
    std::cout << "\n";
}