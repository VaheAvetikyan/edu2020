/*
    14: Լավագույն դասարան
    Գրել ծրագիր, որը մուտքում կստանա դպրոցի ընտրված դասարանների քանակը, ապա յուրաքանյուր դասարանի անվանումը, 
    դասարանում սովորող աշակերտների քանակը, յուրաքանչյուրի անունն ու 5 առարկաների քննությունների գնահատականները։ 
    Ծրագիրը պետք է արտածի ամենաբարձր առաջադիմությամբ դասարանի անվանումը։ Խնդիրը լուծելիս օգտագործել Class և Student դասերը։ 
    Դասարանի առաջադիմությունը դա աշակերտների գնահատականների հանրագումարի և աշակերտների քանակի հարաբերությունն է։ 
*/

#include <iostream>

class Student
{
private:
    std::string lastName;
    std::string firstName;
    const static int COUNT = 5;
    int grades[COUNT];
    int avarageGrade;

public:
    Student(std::string last, std::string first, int arr[]);
    Student();
    ~Student();
    std::string getLastName();
    std::string getFirstName();
    int getGrade(int index);
    double getAvarageGrade();
};

Student::Student(std::string last, std::string first, int arr[]) : lastName(last),
                                                                   firstName(first)
{
    for (int i = 0; i < COUNT; i++)
    {
        grades[i] = arr[i];
    }
}

Student::Student() : firstName(""),
                     lastName("") {}

Student::~Student() {}

std::string Student::getLastName()
{
    return lastName;
}

std::string Student::getFirstName()
{
    return firstName;
}

int Student::getGrade(int index)
{
    return grades[index];
}

double Student::getAvarageGrade()
{
    double sum = 0;
    for (int i = 0; i < COUNT; i++)
    {
        sum += grades[i];
    }
    return sum / COUNT;
}

class Class
{
private:
    std::string className;
    Student *students[10];
    int studentCount = 0;

public:
    Class();
    Class(std::string name);
    ~Class();
    Student getStudent(int index);
    void setStudent(Student *student);
    std::string getClassName();
    int getStudentCount();
    double avarageClassGrade();
};

Class::Class()
{
    className = "";
}

Class::Class(std::string name)
{
    className = name;
}

Class::~Class()
{
    for (int i = 0; i < studentCount; i++)
    {
        delete students[i];
    }
}

Student Class::getStudent(int index)
{
    return *students[index];
}

void Class::setStudent(Student *student)
{
    students[studentCount++] = student;
}

std::string Class::getClassName()
{
    return className;
}

int Class::getStudentCount()
{
    return studentCount;
}

double Class::avarageClassGrade()
{
    double sum = 0;
    for (int i = 0; i < studentCount; i++)
    {
        sum += students[i]->getAvarageGrade();
    }
    return sum / studentCount;
}

int main()
{
    const int COUNT = 5;
    int n;
    std::cin >> n;
    Class **classes = new Class *[n];

    for (int i = 0; i < n; i++)
    {
        int studentCount;
        std::string className;

        std::cin >> className >> studentCount;
        classes[i] = new Class(className);

        for (int j = 0; j < studentCount; j++)
        {
            int grades[COUNT];
            std::string lastName;
            std::string firstName;
            std::cin >> lastName >> firstName;
            for (int iter = 0; iter < COUNT; iter++)
            {
                std::cin >> grades[iter];
            }
            classes[i]->setStudent(new Student(lastName, firstName, grades));
        }
    }

    double maxGrades = 0;
    std::string highestGradedClass;
    for (int i = 0; i < n; i++)
    {
        double avarage = classes[i]->avarageClassGrade();
        if (avarage > maxGrades)
        {
            maxGrades = avarage;
            highestGradedClass = classes[i]->getClassName();
        }
        delete classes[i];
    }
    std::cout << highestGradedClass << "\n";
    delete classes;
}