/*
    1: Չվերթի վերջնակետ-քաղաք
    Գրել ծրագիր, որը մուտքում կստանա N չվերթների մասին տեղեկություն՝ յուրաքանչյուր չվերթի վերջնակետ-քաղաք և գնացքի համար, ապա M քաղաքի անվանում։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի այն գնացքների համարները , որոնք մեկնում են տրված M քաղաքը։ 
    Այդպիսիք չլինելուն դեպքում արտածել “Unreachable city!” հաղորդագրությունը։ (դաս 13)

    Նկարագրել Flight անունով դաս, որն ունի հետևյալ դաշտերը.

    չվերթի վերջնակետ-քաղաք
    գնացքի համարը
*/

#include <iostream>

class Flight
{
private:
    std::string destinationCity;
    std::string trainNumber;

public:
    Flight(std::string dc, std::string tn) : destinationCity(dc), trainNumber(tn) {}

    Flight() : destinationCity(""), trainNumber("") {}

    std::string getDestinationCity()
    {
        return destinationCity;
    }

    std::string getTrainNumber()
    {
        return trainNumber;
    }

    bool isDestionation(std::string city)
    {
        if (destinationCity == city)
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

    std::string city;
    std::string train;
    for (int i = 0; i < n; i++)
    {
        std::cin >> city >> train;
        flights[i] = new Flight(city, train);
    }

    std::string destination;
    std::cin >> destination;

    bool isCityUnreachable = true;

    for (int i = 0; i < n; i++)
    {
        if (flights[i]->isDestionation(destination))
        {
            isCityUnreachable = false;
            std::cout << flights[i]->getTrainNumber() << "\n";
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