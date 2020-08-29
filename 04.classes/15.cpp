/*
    15: Երկրաչափական պատկերներ
    Պահանջվում է գրել ծրագիր որում իրականցված են հետևյալ դասերը՝ Shape, Triangle, Rectangle, Circle

    Shape դասը հանդիսանում է բազային աբստրակտ դաս մնացած դասերի համար և դրանից ժառանգված դասերի օբյեկտներն իրենցից ներկայացնում են երկրաչափական պատկերներ
    Triangle դասի օբյեկտները եռանկյուններ են
    Rectangle դասի օբյեկտներն ուղղանկյուններ են
    Circle դասի օբյեկտները շրջաններ են
    Դասերի մեթոդներ.

    Shape դասից ժառանգված բոլոր դասերը պետք է պարունակեն տվյալ դասի օբյեկտ ստեղծելու համար անհրաժեշտ կոնստրուկտոր(ներ) կամ մեթոդներ
    Պատկերի մակերեսը հաշվող ֆունկցիա, որը Shape դասում պետք է սահմանված լինի որպես մաքուր վիրտուալ ֆունկցիա
    Ծրագիրը մուտքում կստանա N մարմինների անունները և նրանց չափերը (եռանկյան դեպքում հիմքը ապա բարձրությունը)։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի բոլոր մարմինների մակերեսները աճման կարգով։
*/

#include <iostream>

class Shape
{
public:
    virtual ~Shape() {}
    virtual double getArea() = 0;
    void printArea()
    {
        std::cout << getArea() << "\n";
    }
};

class Triangle : public Shape
{
public:
    Triangle(double b, double h) : base(b), height(h) {}
    virtual ~Triangle() {}
    virtual double getArea()
    {
        return (base * height) / 2;
    }

private:
    double base;
    double height;
};

class Rectangle : public Shape
{
public:
    Rectangle(double s1, double s2) : side1(s1), side2(s2) {}
    virtual ~Rectangle() {}
    virtual double getArea()
    {
        double p = side1 * 2 + side2 * 2;
        return side1 * side2;
    }

private:
    double side1;
    double side2;
};

class Circle : public Shape
{
public:
    const double PI = 3.1415;

    Circle(double r) : radius(r) {}
    virtual ~Circle() {}
    virtual double getArea()
    {
        return PI * radius * radius;
    }

private:
    double radius;
};

void bubbleSort(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j+1] and arr[i]
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    Shape *shapePointerArray[n];

    for (int i = 0; i < n; i++)
    {
        std::string shape;
        std::cin >> shape;
        if (shape.compare("Triangle") == 0)
        {
            double base, height;
            std::cin >> base >> height;
            shapePointerArray[i] = new Triangle(base, height);
        }
        else if (shape.compare("Rectangle") == 0)
        {
            double side1, side2;
            std::cin >> side1 >> side2;
            shapePointerArray[i] = new Rectangle(side1, side2);
        }
        else if (shape.compare("Circle") == 0)
        {
            double radius;
            std::cin >> radius;
            shapePointerArray[i] = new Circle(radius);
        }
    }

    double areas[n];
    for (int i = 0; i < n; i++)
    {
        areas[i] = shapePointerArray[i]->getArea();
        delete shapePointerArray[i];
    }

    bubbleSort(areas, n);
    for (size_t i = 0; i < n; i++)
    {
        std::cout << areas[i] << " ";
    }
    std::cout << "\n";
}