/*
    16: Երկրաչափական մարմիններ
    Պահանջվում է գրել ծրագիր որում իրականցված են հետևյալ դասերը՝ Shape, Cube, Pyramid, Ball

    Shape դասը հանդիսանում է բազային աբստրակտ դաս մնացած դասերի համար և դրանից ժառանգված դասերի օբյեկտներն 
        իրենցից ներկայացնում են երկրաչափական եռաչափ մարմիններ
    Cube դասի օբյեկտները խորանարդներ են
    Pyramid դասի օբյեկտներն քառակուսի բուրգեր են
    Ball դասի օբյեկտները գնդեր են
    Դասերի մեթոդներ.

    Shape դասից ժառանգված բոլոր դասերը պետք է պարունակեն տվյալ դասի օբյեկտ ստեղծելու համար անհրաժեշտ կոնստրուկտոր(ներ) կամ մեթոդներ
    Մարմինների ծավալ հաշվող ֆունկցիա, որը Shape դասում պետք է սահմանված լինի որպես մաքուր վիրտուալ ֆունկցիան
    Ծրագիրը մուտքում կստանա N մարմինների անունները և նրանց չափերը (բուրգի դեպքում նախ հիմք կողմի երկարությունը ապա բարձրությունը)։ 
    Որպես ծրագրի աշխատանքի արդյունք այն պետք է արտածի բոլոր մարմինների ծավալների գումարը։
*/

#include <iostream>

class Shape
{
public:
    virtual ~Shape() {}
    virtual double getVolume() = 0;
};

class Cube : public Shape
{
public:
    Cube(double s) : side(s) {}
    virtual ~Cube() {}
    virtual double getVolume()
    {
        return side * side * side;
    }

private:
    double side;
};

class Pyramid : public Shape
{
public:
    Pyramid(double b, double h) : base(b), height(h) {}
    virtual ~Pyramid() {}
    virtual double getVolume()
    {
        return (base * base * height) / 3;
    }

private:
    double base;
    double height;
};

class Ball : public Shape
{
public:
    const double PI = 3.1415;

    Ball(double r) : radius(r) {}
    virtual ~Ball() {}
    virtual double getVolume()
    {
        return (4 * PI * radius * radius * radius) / 3;
    }

private:
    double radius;
};

int main()
{
    int n;
    std::cin >> n;
    Shape *shapePointerArray[n];

    for (int i = 0; i < n; i++)
    {
        std::string shape;
        std::cin >> shape;
        if (shape.compare("Cube") == 0)
        {
            double base;
            std::cin >> base;
            shapePointerArray[i] = new Cube(base);
        }
        else if (shape.compare("Pyramid") == 0)
        {
            double base, height;
            std::cin >> base >> height;
            shapePointerArray[i] = new Pyramid(base, height);
        }
        else if (shape.compare("Ball") == 0)
        {
            double radius;
            std::cin >> radius;
            shapePointerArray[i] = new Ball(radius);
        }
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += shapePointerArray[i]->getVolume();
        delete shapePointerArray[i];
    }
    std::cout << sum << "\n";
}