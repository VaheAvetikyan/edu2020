/*
    8: Լավագույն աշակերտ
    Գրել ծրագիր, որը մուտքում կստանա դասարանի աշակերտների քանակը ապա յուրաքանչյուրի անունն և 5 առարկաների քննությունների գնահատականները։ 
    Ծրագիրը պետք է արտածի ամենաբարձր միջին որակական գնահատական ունեցող աշակերտի անունը։
*/

#include <iostream>

class Student
{
private:
    std::string firstName;
    std::string lastName;
    int *grades = new int[5];

public:
    Student(std::string first, std::string last) : firstName(first), lastName(last) {}
    Student() : firstName(""), lastName("") {}
    ~Student()
    {
        delete grades;
    }

    void inputGrades()
    {
        for (int i = 0; i < 5; i++)
        {
            std::cin >> grades[i];
        }
    }

    std::string getFirstName()
    {
        return firstName;
    }

    std::string getLastName()
    {
        return lastName;
    }

    double avarageGrade()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += grades[i];
        }
        return sum / 5;
    }
};

int main()
{
    int n;
    std::cin >> n;
    Student *students[n];

    std::string first, last;
    int arr[5];
    for (int i = 0; i < n; i++)
    {
        std::cin >> first >> last;
        students[i] = new Student(first, last);
        students[i]->inputGrades();
    }

    int index;
    double maxGrade = 0;
    for (int i = 0; i < n; i++)
    {
        double currentGrade = students[i]->avarageGrade();
        if (currentGrade > maxGrade)
        {
            index = i;
            maxGrade = currentGrade;
        }
    }

    std::cout << students[index]->getFirstName() << " " << students[index]->getLastName() << "\n";

    // Delete allocated objects
    for (int i = 0; i < n; i++)
    {
        delete students[i];
    }
}