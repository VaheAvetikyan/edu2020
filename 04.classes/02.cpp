/*
    2: Նշված օրը
    Գրել ծրագիր, որը մուտքում կստանա N չվերթների մասին տեղեկություն՝ յուրաքանչյուր չվերթի վերջնակետ-քաղաք, գնացքի համար և մեկնելու օր, ապա M քաղաքի անվանում և D օր։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի այն գնացքների համարները, որոնք տրված D օրը մեկնում են M քաղաքը։ 
    Այդպիսիք չլինելուն դեպքում արտածել “Unreachable city!” հաղորդագրությունը։ (դաս 13)

    Նկարագրել Flight անունով դաս, որն ունի հետևյալ դաշտերը.

    չվերթի վերջնակետ-քաղաք
    չվերթի օր
    գնացքի համարը
*/

#include <iostream>

class Flight
{
private:
    std::string destinationCity;
    std::string trainNumber;
    int dayOfTheMonth;

public:
    Flight(std::string dc, std::string tn, int dotm) : destinationCity(dc), trainNumber(tn), dayOfTheMonth(dotm)
    {
        if (dotm <= 0)
        {
            dayOfTheMonth = 1;
        }
        else if (dotm > 31)
        {
            dayOfTheMonth = 31;
        }
    }

    Flight() : destinationCity(""), trainNumber(""), dayOfTheMonth(1) {}

    std::string getDestinationCity()
    {
        return destinationCity;
    }

    std::string getTrainNumber()
    {
        return trainNumber;
    }

    int getDayOfTheMonth()
    {
        return dayOfTheMonth;
    }

    bool isDestionationToday(std::string city, int day)
    {
        if (destinationCity == city && dayOfTheMonth == day)
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
    int day;
    for (int i = 0; i < n; i++)
    {
        std::cin >> city >> train >> day;
        flights[i] = new Flight(city, train, day);
    }

    std::string destination;
    int thisDay;
    std::cin >> destination >> thisDay;

    bool isCityUnreachable = true;

    for (int i = 0; i < n; i++)
    {
        if (flights[i]->isDestionationToday(destination, thisDay))
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