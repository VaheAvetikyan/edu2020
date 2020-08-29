/*
    5: Նախատեսված է ...
    Գրել ծրագիր, որը մուտքում կստանա N հեռուստացույցների մասին տեղեկություն՝ 
    յուրաքանչյուր հեռուստացույցի մոդելի անուն, արտադրող երկիր և վաճառքի երկիր, ապա հեռուստացույցի A արտադրման երկիրը և B վաճառքի երկիրը։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի բոլոր հեռուստացույցների մոդելները որոնք արտադրվում են A երկրում և վաճառվում B֊ում։ 
    Այդպիսիք չլինելուն դեպքում արտածել “Not found!” հաղորդագրությունը։ (դաս 13)

    Նկարագրել TV անունով դաս, որն կունենա հետևյալդաշտերը.

    TV մոդելի անուն
    արտադրող երկիր
    վաճառքի երկիր
*/

#include <iostream>

class TV
{
private:
    std::string modelName;
    std::string producerCountry;
    std::string sellerCountry;

public:
    TV(std::string name, std::string producer, std::string seller) : modelName(name), producerCountry(producer), sellerCountry(seller) {}

    TV() : modelName(""), producerCountry(""), sellerCountry("") {}

    std::string getModelName()
    {
        return modelName;
    }

    std::string getProducerCountry()
    {
        return producerCountry;
    }

    std::string getSellerCountry()
    {
        return sellerCountry;
    }
};

int main()
{
    int n;
    std::cin >> n;
    TV *tvs[n];

    std::string name;
    std::string producer;
    std::string seller;
    for (int i = 0; i < n; i++)
    {
        std::cin >> name >> producer >> seller;
        tvs[i] = new TV(name, producer, seller);
    }

    std::string country1;
    std::string country2;
    std::cin >> country1 >> country2;
    bool notFound = true;
    for (int i = 0; i < n; i++)
    {
        if (country1.compare(tvs[i]->getProducerCountry()) == 0 && country2.compare(tvs[i]->getSellerCountry()) == 0)
        {
            notFound = false;
            std::cout << tvs[i]->getModelName() << "\n";
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