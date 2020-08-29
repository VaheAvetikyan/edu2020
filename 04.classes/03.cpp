/*
3: Տարանցիկ
Գրել ծրագիր, որը մուտքում կստանա N չվերթների մասին տեղեկություն՝ 
յուրաքանչյուր չվերթի սկզբնակետ-քաղաք, վերջնակետ-քաղաք և գնացքի համար, ապա A, B և C քաղաքների անվանումները։ 
Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի չվերթների համարների զույգեր, 
զույգի առաջին գնացքը պետք է անցնի A-ից B, իսկ երկրորդը՝ B-ից C. Չ
վերթների համարները պետք է արտածվեն նույն հերթականությամբ ոնց ներմուծվել էին․ 
Այդպիսիք չլինելուն դեպքում արտածել “Unreachable city!” հաղորդագրությունը։ (դաս 13)

Նկարագրել TRAIN անունով դաս, որն ունի հետևյալ դաշտերը.

չվերթի սկզբնակետ-քաղաք
չվերթի վերջնակետ-քաղաք
գնացքի համարը
*/

#include <iostream>

class Flight
{
private:
    std::string originCity;
    std::string destinationCity;
    std::string trainNumber;

public:
    Flight(std::string oc, std::string dc, std::string tn) : originCity(oc), destinationCity(dc), trainNumber(tn) {}

    Flight() : originCity(""), destinationCity(""), trainNumber("") {}

    std::string getOriginCity()
    {
        return originCity;
    }

    std::string getDestinationCity()
    {
        return destinationCity;
    }

    std::string getTrainNumber()
    {
        return trainNumber;
    }

    bool isFromTo(std::string origin, std::string destination)
    {
        if (originCity == origin && destinationCity == destination)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    std::cin >> n;
    Flight *flights[n];

    std::string originCity;
    std::string destinationCity;
    std::string train;
    for (int i = 0; i < n; i++)
    {
        std::cin >> originCity >> destinationCity >> train;
        flights[i] = new Flight(originCity, destinationCity, train);
    }

    std::string origin;
    std::string transit;
    std::string destination;
    std::cin >> origin >> transit >> destination;

    bool isCityUnreachable = true;

    for (int i = 0; i < n; i++)
    {
        if (flights[i]->isFromTo(origin, transit))
        {
            for (int j = 0; j < n; j++)
            {
                if (flights[j]->isFromTo(transit, destination))
                {
                    isCityUnreachable = false;
                    std::cout << flights[i]->getTrainNumber() << "\n";
                    std::cout << flights[j]->getTrainNumber() << "\n";
                    break;
                }
            }
            if (!isCityUnreachable)
            {
                break;
            }
        }
    }

    if (isCityUnreachable)
    {
        std::cout << "Unreachable city!\n";
    }

    // Delete allocated objects
    for (int i = 0; i < n; i++)
    {
        delete flights[i];
    }
}