/*
    17: Միջինից բարձր աշխատավարձ
    Պահանջվում է գրել ծրագիր որում իրականցված են Person և Employee դասերը։ 
    Person դասի օբյեկտները մարդիկ են, իսկ Employee դասը ժառանգված է Person դասից, և այդ դասի օբյեկտները աշխատողներ են:

    Դասերի դաշտեր.
    Person դասում առնվազն պետք է լինեն անուն, ազգանուն դաշտերը
    Employee դասում առնվազն պետք է լինեն պաշտոն և աշխատավարձ դաշտերը
    Ծրագիրը մուտքում պետք է ստանա N աշխատողների տվյալները հերթականությամբ՝ անուն, ազգանուն, պաշտոն և աշխատավարձ։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի բոլոր աշխատողների ազգանունները և պաշտոնները, որոնց աշխատավարձը միջին աշխատավարձից ցածր չէ։
*/

#include <iostream>

class Person
{
private:
    std::string lastName;
    std::string firstName;

public:
    Person(std::string last, std::string first) : lastName(last), firstName(first) {}
    Person() : lastName(""), firstName("") {}
    ~Person() {}
    std::string getLastName();
    std::string getFirstName();
};

std::string Person::getLastName()
{
    return lastName;
}

std::string Person::getFirstName()
{
    return firstName;
}

class Employee : public Person
{
private:
    std::string position;
    int wage;

public:
    Employee(std::string last, std::string first, std::string p, int w) : Person(last, first), position(p), wage(w) {}
    Employee() : Person(), position(""), wage(0) {}
    ~Employee() {}
    std::string getPosition();
    int getWage();
};

std::string Employee::getPosition()
{
    return position;
}

int Employee::getWage()
{
    return wage;
}

int main()
{
    int n;
    std::cin >> n;
    Employee **employees = new Employee *[n];
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::string lastName;
        std::string firstName;
        std::string position;
        int wage;
        std::cin >> firstName >> lastName >> position >> wage;
        employees[i] = new Employee(lastName, firstName, position, wage);
        sum += wage;
    }
    double avarageWage = sum / n;
    for (int i = 0; i < n; i++)
    {
        if (employees[i]->getWage() >= avarageWage)
        {
            std::cout << employees[i]->getLastName() << " " << employees[i]->getPosition() << "\n";
        }
        delete employees[i];
    }
    delete employees;
}