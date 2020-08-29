/*
    19: Ամենաբարձր ժողովրդականություն
    Պահանջվում է գրել ծրագիր, որում իրականցված են հետևյալ դասերը՝ Book, FictionBook, ScientificBook
    
    Book դասի օբյեկտները գրքեր են
    FictionBook դասը ժառանված է Book դասից և այդ դասի օբյեկտները գեղարվեստական գրքեր են
    ScientificBook դասը ժառանված է Book դասից և այդ դասի օբյեկտները գիտական գրքեր են
    Դասերի դաշտեր.

    Book դասում պետք է լինի վերնագիր դաշտը
    FictionBook դասում պետք է լինեն վաճառված օրինակների քանակ և տպաքանակ դաշտերը
    ScientificBook դասում պետք է լինեն գրքի գին, էջերի քանակ և գրադարաններին տրված օրինակների քանակ դաշտերը

    Դասերի մեթոդներ.
    Book, FictionBook, ScientificBook դասի օբյեկտներ ստեղծելու համար անհրաժեշտ կոնստրուկտորներ
    popularity անունով ֆունկցիա, որը հաշվում է գեղարվեստական գրքի ժողովրդականությունը 
        (որպես սահող ստորակետով թիվ) հետևյալ բանաձևով՝ (s / c) * (s / 1000), որտեղ s-ը գրքի վաճառված օրինակների քանակն է, իսկ c-ն գրքի տպաքանակն է
    expensive անունով ֆունկցիա, որը հաշվում է գիտական գրքի թանկարժեքության աստիճանը 
        (որպես սահող ստորակետով թիվ) հետևյալ բանաձևով՝ գին/էջերի քանակ
    Ծրագիրը մուտքում պետք է ստանա N գեղարվեստական գրքերի տվյալները հերթականությամբ՝ 
        վերնագիր, տպաքանակ, վաճառված օրինակների քանակ։ 
    Ապա M գիտական գրքերի տվյալներ հերթականությամբ՝ վերնագիր, գին, էջերի քանակ, գրադարաններին տրված գրքերի քանակ։

    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի այն գեղարվեստական գրքերի վերնագրերը որոնք ունեն ամենաբարձր ժողովրդականությունը։ 
    Ինչպես նաև այն գիտական գրքի վերնագիը, որը ամենաշատն է տրվել գրադարաններին և ունի միջինից ցածր թանկարժեքություն, 
    այդպիսին չլինելու դեպքում արտածել "Not found!"։ 
*/

#include <iostream>

class Book
{
private:
    std::string title;

public:
    Book(std::string title) : title(title) {}
    Book() : title("") {}
    ~Book() {}
    std::string getTitle()
    {
        return title;
    }
};

class FictionBook : public Book
{
private:
    int copies;
    int sold;

public:
    FictionBook(std::string t, int c, int s) : Book(t), copies(c), sold(s) {}
    FictionBook() : Book(), copies(0), sold(0) {}
    ~FictionBook() {}
    int getCopies()
    {
        return copies;
    }
    int getSold()
    {
        return sold;
    }

    double popularity()
    {
        return ((double)sold / (double)copies) * ((double)sold / 1000);
    }
};

class ScientificBook : public Book
{
private:
    int price;
    int pages;
    int countInLibraries;

public:
    ScientificBook(std::string t, int p, int pg, int c) : Book(t), price(p), pages(pg), countInLibraries(c) {}
    ScientificBook() : Book(), price(0), pages(0), countInLibraries(0) {}
    ~ScientificBook() {}
    int getPrice()
    {
        return price;
    }
    int getPages()
    {
        return pages;
    }
    int getCountInLibraries()
    {
        return countInLibraries;
    }
    double expensive()
    {
        return (double)price / pages;
    }
};

int main()
{
    int n;
    std::cin >> n;
    FictionBook **fictionBooks = new FictionBook *[n];

    for (int i = 0; i < n; i++)
    {
        std::string title;
        int copies;
        int sold;
        std::cin.ignore(40, '\n');
        std::getline(std::cin, title);
        std::cin >> copies >> sold;
        fictionBooks[i] = new FictionBook(title, copies, sold);
    }

    int m;
    std::cin >> m;
    ScientificBook **scientificBooks = new ScientificBook *[m];

    for (int i = 0; i < m; i++)
    {
        std::string title;
        int price;
        int pages;
        int inLib;
        std::cin.ignore(40, '\n');
        std::getline(std::cin, title);
        std::cin >> price >> pages >> inLib;
        scientificBooks[i] = new ScientificBook(title, price, pages, inLib);
    }

    double maxPopularity = 0;
    for (int i = 0; i < n; i++)
    {
        double p = fictionBooks[i]->popularity();
        if (p >= maxPopularity)
        {
            maxPopularity = p;
        }
    }

    int maxInLib = 0;
    double accumulativeExpensive;
    for (int i = 0; i < m; i++)
    {
        accumulativeExpensive += scientificBooks[i]->expensive();
        int p = scientificBooks[i]->getCountInLibraries();
        if (p > maxInLib)
        {
            maxInLib = p;
        }
    }
    double avgExpencive = accumulativeExpensive / m;

    // Free allocated mamory
    for (int i = 0; i < n; i++)
    {
        if (fictionBooks[i]->popularity() == maxPopularity)
        {
            std::cout << fictionBooks[i]->getTitle() << "\n";
        }
        delete fictionBooks[i];
    }

    bool found = false;
    for (int i = 0; i < m; i++)
    {
        if (scientificBooks[i]->expensive() < avgExpencive && scientificBooks[i]->getCountInLibraries() == maxInLib)
        {
            found = true;
            std::cout << scientificBooks[i]->getTitle() << "\n";
        }
        delete scientificBooks[i];
    }
    delete[] fictionBooks;
    delete[] scientificBooks;

    if (!found)
    {
        std::cout << "Not found!\n";
    }
}