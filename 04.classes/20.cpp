/*
    20: Մաթեմատիկոս պոետը
    Պահանջվում է գրել ծրագիր, որում իրականցված են հետևյալ դասերը՝ Book, FictionBook, ScientificBook

    Book դասի օբյեկտները գրքեր են
    FictionBook դասը ժառանված է Book դասից և այդ դասի օբյեկտները գեղարվեստական գրքեր են
    ScientificBook դասը ժառանված է Book դասից և այդ դասի օբյեկտները գիտական գրքեր են
    Դասերի դաշտեր.

    Book դասում պետք է լինեն հեղինակի անուն և ազգանուն դաշտերը
    FictionBook դասում պետք է լինի ժանր դաշտը՝ ՛novel՛, ՛story՛ և ՛poem՛ արժեքներից մեկով
    ScientificBook դասում պետք է լինի բնագավառ դաշտը՝ ՛informatics՛, ‘physics’, ‘mathematics’ և ‘chemistry’ արժեքներից մեկով
    Ծրագիրը մուտքում պետք է ստանա N գեղարվեստական գրքերի տվյալները հերթականությամբ՝ հեղինակի անուն, ազգանուն և ժանր։ 
    Ապա M գիտական գրքերի տվյալներ հերթականությամբ՝ հեղինակի անուն և բնագավառ։

    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի այն մաթեմատիկոսների անունները որոնք ունեն հրատարակված պոեմներ, 
    եթե չկան այդպիսիք արտածի “Not found!”։ 
*/

#include <iostream>

class Book
{
private:
    std::string first;
    std::string last;

public:
    Book(std::string f, std::string l) : first(f), last(l) {}
    Book() : first(""), last("") {}
    ~Book() {}
    std::string getName()
    {
        return first + " " + last;
    }
};

class FictionBook : public Book
{
private:
    std::string genre;

public:
    FictionBook(std::string f, std::string l, std::string g) : Book(f, l), genre(g) {}
    FictionBook() : Book(), genre("") {}
    ~FictionBook() {}
    std::string getGenre()
    {
        return genre;
    }
};

class ScientificBook : public Book
{
private:
    std::string genre;

public:
    ScientificBook(std::string f, std::string l, std::string g) : Book(f, l), genre(g) {}
    ScientificBook() : Book(), genre("") {}
    ~ScientificBook() {}
    std::string getGenre()
    {
        return genre;
    }
};

int main()
{
    int n;
    std::cin >> n;
    FictionBook **fictionBooks = new FictionBook *[n];

    for (int i = 0; i < n; i++)
    {
        std::string f, l, g;
        std::cin >> f >> l >> g;
        fictionBooks[i] = new FictionBook(f, l, g);
    }

    int m;
    std::cin >> m;
    ScientificBook **scientificBooks = new ScientificBook *[m];

    for (int i = 0; i < m; i++)
    {
        std::string f, l, g;
        std::cin >> f >> l >> g;
        scientificBooks[i] = new ScientificBook(f, l, g);
    }

    bool found = false;
    for (int i = 0; i < m; i++)
    {
        if (scientificBooks[i]->getGenre().compare("mathematics") == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (fictionBooks[j]->getGenre().compare("poem") == 0 && scientificBooks[i]->getName().compare(fictionBooks[j]->getName()) == 0)
                {
                    found = true;
                    std::cout << scientificBooks[i]->getName() << "\n";
                }
            }
        }
    }

    // Free allocated mamory
    for (int i = 0; i < n; i++)
    {
        delete fictionBooks[i];
    }

    for (int i = 0; i < m; i++)
    {
        delete scientificBooks[i];
    }
    delete[] fictionBooks;
    delete[] scientificBooks;

    if (!found)
    {
        std::cout << "Not found!\n";
    }
}