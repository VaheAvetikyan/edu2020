/*
    18: Առավելագույն աշխատավարձ ստացող նվազագույն տարիքով
    Պահանջվում է գրել ծրագիր, որում իրականցված են Person և Employee դասերը։ 
    Person դասի օբյեկտները մարդիկ են, իսկ Employee դասը ժառանգված է Person դասից, և այդ դասի օբյեկտները աշխատողներ են:

    Դասերի դաշտեր.
    Person դասում առնվազն պետք է լինեն անուն, ազգանուն և ծննդյան տարեթիվ դաշտերը
    Employee դասում առնվազն պետք է լինի աշխատավարձ դաշտերը
    Ծրագիրը մուտքում պետք է ստանա N աշխատողների տվյալները հերթականությամբ՝ անուն, ազգանուն, ծննդյան տարեթիվ և աշխատավարձ։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի առավելագույն աշխատավարձ ստացող նվազագույն տարիքով աշխատողների ազգանունները, 
    այդպիսիք չլինելու դեպքում արտածի "Not found!": 
*/

#include <iostream>

class Person
{
private:
    std::string lastName;
    std::string firstName;
    int birthYear;

public:
    Person(std::string last, std::string first, int year) : lastName(last), firstName(first), birthYear(year) {}
    Person() : lastName(""), firstName(""), birthYear(1900) {}
    ~Person() {}
    std::string getLastName();
    std::string getFirstName();
    int getBirthYear();
};

std::string Person::getLastName()
{
    return lastName;
}

std::string Person::getFirstName()
{
    return firstName;
}

int Person::getBirthYear()
{
    return birthYear;
}

class Employee : public Person
{
private:
    int wage;

public:
    Employee(std::string last, std::string first, int year, int w) : Person(last, first, year), wage(w) {}
    Employee() : Person(), wage(0) {}
    ~Employee() {}
    int getWage();
};

int Employee::getWage()
{
    return wage;
}

int main()
{
    int n;
    std::cin >> n;
    Employee **employees = new Employee *[n];
    int maxYear = 0;
    int maxWage = 0;

    for (int i = 0; i < n; i++)
    {
        std::string lastName;
        std::string firstName;
        int year;
        int wage;
        std::cin >> firstName >> lastName >> year >> wage;
        employees[i] = new Employee(lastName, firstName, year, wage);

        if (maxYear < year)
        {
            maxYear = year;
        }
        if (maxWage < wage)
        {
            maxWage = wage;
        }
    }

    bool notFound = true;
    for (int i = 0; i < n; i++)
    {
        if (employees[i]->getBirthYear() == maxYear && employees[i]->getWage() == maxWage)
        {
            notFound = false;
            std::cout << employees[i]->getLastName() << "\n";
        }
        delete employees[i];
    }

    if (notFound)
    {
        std::cout << "Not found!\n";
    }

    delete employees;
}