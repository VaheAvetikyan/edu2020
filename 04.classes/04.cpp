/*
    4: Պահանջվող մոդել
    Գրել ծրագիր, որը մուտքում կստանա N հեռուստացույցների մասին տեղեկություն՝ 
    յուրաքանչյուր հեռուստացույցի մոդելի անուն, արտադրող երկիր և անկյունագծի երկարություն, ապա M մոդելի անվանումը։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի բոլոր տրված M մոդելի հեռուստացույցների անկյունագծի չափերը և արտադրող երկիրը։ 
    Այդպիսիք չլինելուն դեպքում արտածել “Not found!” հաղորդագրությունը։ (դաս 13)

    Նկարագրել TV անունով դաս, որն կունենա հետևյալ դաշտերը.

    TV մոդելի անուն
    արտադրող երկիր
    անկյունագծի երկարություն
*/

#include <iostream>

class TV
{
private:
    std::string modelName;
    std::string producerCountry;
    double diagonal;

public:
    TV(std::string name, std::string country, double d) : modelName(name), producerCountry(country), diagonal(d) {}

    TV() : modelName(""), producerCountry(""), diagonal(0) {}

    std::string getModelName()
    {
        return modelName;
    }

    std::string getProducerCountry()
    {
        return producerCountry;
    }

    double getDiagonal()
    {
        return diagonal;
    }
};

int main()
{
    int n;
    std::cin >> n;
    TV *tvs[n];

    std::string name;
    std::string country;
    double diagonal;
    for (int i = 0; i < n; i++)
    {
        std::cin >> name >> country >> diagonal;
        tvs[i] = new TV(name, country, diagonal);
    }

    std::string model;
    std::cin >> model;
    bool notFound = true;
    for (int i = 0; i < n; i++)
    {
        if (model.compare(tvs[i]->getModelName()) == 0)
        {
            notFound = false;
            std::cout << tvs[i]->getProducerCountry() << " " << tvs[i]->getDiagonal() << "\n";
        }
    }

    if (notFound)
    {
        std::cout << "Not found!\n";
    }

    // Delete allocated objects
    for (int i = 0; i < n; i++)
    {
        delete tvs[i];
    }
}