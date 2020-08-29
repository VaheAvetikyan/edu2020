/*
    13: Աշխատում են A-15-ում
    Հայտնի է, արտադրամասում կան առանձին բանվորական խմբեր, որոնք ունեն արտադրամասի համարներ, որում աշխատում են։ 
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա խմբերի քանակը, ապա ըստ հերթականության յուրաքանչյուր խմբի արտադրամասի անվանումը, 
    խմբում բանվորների քանակը և յուրաքանչյուր բանվորի անունն ու ծննդյան թիվը։ 
    Ծրագիրը պետք է արտածի բոլոր այն բանվորների անունները, որոնք աշխատում են A-15 արտադրամասում։ 
    Այդպիսիք չլինելու դեպքում արտածել “Not found!” հաղորդագրությունը։ Ծրագիրը լուծելիս օգտագործել Group և Worker դասերը։ 
*/

#include <iostream>

class Worker
{
private:
    std::string lastName;
    std::string firstName;
    int birthYear;

public:
    Worker(std::string last, std::string first, int year);
    Worker();
    ~Worker();
    std::string getLastName();
    std::string getFirstName();
    int getBirthYear();
};

Worker::Worker(std::string last, std::string first, int year) : lastName(last),
                                                                firstName(first),
                                                                birthYear(year) {}

Worker::Worker() : firstName(""),
                   lastName(""),
                   birthYear(1900) {}

Worker::~Worker() {}

std::string Worker::getLastName()
{
    return lastName;
}

std::string Worker::getFirstName()
{
    return firstName;
}

int Worker::getBirthYear()
{
    return birthYear;
}

class Group
{
private:
    std::string groupName;
    Worker *workers[10];
    int workerCount = 0;

public:
    Group();
    Group(std::string name);
    ~Group();
    Worker getWorker(int index);
    void setWorker(Worker *worker);
    std::string getGroupName();
    int getWorkerCount();
};

Group::Group()
{
    groupName = "";
}

Group::Group(std::string name)
{
    groupName = name;
}

Group::~Group()
{
    for (int i = 0; i < workerCount; i++)
    {
        delete workers[i];
    }
}

Worker Group::getWorker(int index)
{
    return *workers[index];
}

void Group::setWorker(Worker *worker)
{
    workers[workerCount++] = worker;
}

std::string Group::getGroupName()
{
    return groupName;
}

int Group::getWorkerCount()
{
    return workerCount;
}

int main()
{
    const std::string GROUP = "A-15";
    int n;
    std::cin >> n;
    Group **groups = new Group *[n];

    for (int i = 0; i < n; i++)
    {
        int workersCount;
        std::string groupName;

        std::cin >> groupName >> workersCount;
        groups[i] = new Group(groupName);

        for (int j = 0; j < workersCount; j++)
        {
            std::string lastName;
            std::string firstName;
            int year;
            std::cin >> lastName >> firstName >> year;
            groups[i]->setWorker(new Worker(lastName, firstName, year));
        }
    }

    bool checkedAllGroups = true;
    for (int i = 0; i < n; i++)
    {
        if (GROUP.compare(groups[i]->getGroupName()) == 0)
        {
            checkedAllGroups = false;
            int m = groups[i]->getWorkerCount();
            for (int j = 0; j < m; j++)
            {
                std::cout << groups[i]->getWorker(j).getLastName() << " " << groups[i]->getWorker(j).getFirstName() << "\n";
            }
        }
        delete groups[i];
    }

    if (checkedAllGroups)
    {
        std::cout << "Not found!\n";
    }

    delete groups;
}