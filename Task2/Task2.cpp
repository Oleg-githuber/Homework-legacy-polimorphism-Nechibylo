/*
В этом задании вы усложните иерархию классов для усложнённой предметной области.

У вас появляется информация о длине сторон и углах ваших фигур, а также несколько более конкретных фигур. Теперь в треугольнике вы должны хранить информацию о длине всех его трёх сторон (a, b, c) и значениях его трёх углов (A, B, C). В четырёхугольнике вы храните информацию о длине его четырёх сторон (a, b, c, d) и значениях его четырёх углов (A, B, C, D).

Также у вас появляются более конкретные фигуры:

прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равны, углы A и C равны);
равносторонний треугольник (все стороны равны, все углы равны 60);
прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
квадрат (все стороны равны, все углы равны 90);
параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
ромб (все стороны равны, углы A,C и B,D попарно равны).
Вы должны иметь возможность узнать у каждой фигуры длины её сторон и значения её углов, но извне вы не должны быть способны изменить длины сторон и углы.

Не должно быть возможности создать фигуры, не удовлетворяющие перечисленным условиям. Например, нельзя создать квадрат с разными углами. Геометрические соотношения проверять не нужно. Например, сумма углов в треугольнике может быть не равна 180.

Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонстрируйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о длинах её сторон и величине её углов. Значения используйте произвольные.

Инициализацию длин сторон и величин углов нужно выполнить с помощью вызова базовых конструкторов.

Для вывода информации о фигуре создайте функцию print_info, которая будет принимать в качестве аргумента указатель на базовый класс фигуры.*/

#include <iostream>
#include <clocale>
#include <string>

class Figure
{
private:

    std::string name{};
    int sidesCount{};
    int sides[4] = {};
    int angles[4] = {};

protected:

    Figure(int value, std::string str) : sidesCount{value}, name{ str }
    {}

    void setSides(int* array)
    {
        for (int i{ 0 }; i < sidesCount; ++i)
        {
            sides[i] = array[i];
        }
    }

    void setAngles(int* array)
    {
        for (int i{ 0 }; i < sidesCount; ++i)
        {
            angles[i] = array[i];
        }
    }

public:

    std::string getName() { return name; }

    int getSidesCount() { return sidesCount; }

    int* getSides() { return sides; }

    int* getAngles() { return angles; }

    Figure() = default;
};

// Треугольник
class Triangle : public Figure
{
private:
   
    void initTriangle(int aSide, int bSide, int cSide, int AAngle, int BAngle, int CAngle)
    {
        int arrSides[] = { aSide, bSide, cSide };
        setSides(arrSides);
        int arrAngles[] = { AAngle, BAngle, CAngle };
        setAngles(arrAngles);
    }

protected:

    Triangle(std::string newName, int aSide, int bSide, int cSide, int AAngle, int BAngle, int CAngle) :
        Figure{ 3, newName }
    {
        initTriangle(aSide, bSide, cSide, AAngle, BAngle, CAngle);
    }

public:

    Triangle() : Triangle{ 10, 20, 30, 50, 60, 70 }
    {}

    Triangle(int aSide, int bSide, int cSide, int AAngle, int BAngle, int CAngle) :
        Figure{3, "Треугольник" }
    {
        initTriangle(aSide, bSide, cSide, AAngle, BAngle, CAngle);
    }
};

// Прямоугольный треугольник
class RectangularTriangle : public Triangle
{
public:

    RectangularTriangle() : RectangularTriangle{10, 20, 30, 50, 60 }
    {}

    RectangularTriangle(int a, int b, int c, int A, int B) : Triangle{"Прямоугольный треугольник", a, b, c, A, B, 90 }
    {}
};

// Равнобедренный треугольник
class IsoscelesTriangle : public Triangle
{
protected:

    IsoscelesTriangle(std::string newName, int a, int b, int A, int B) : Triangle{ newName, a, b, a, A, B, A }
    {}

public:

    IsoscelesTriangle() : IsoscelesTriangle{ 10, 20, 50, 60 }
    {}

    IsoscelesTriangle(int a, int b, int A, int B) : Triangle{ "Равнобедренный треугольник", a, b, a, A, B, A }
    {}
};

// Равосторонний треугольник
class PerfectTriangle : public IsoscelesTriangle
{
public:

    PerfectTriangle() : PerfectTriangle{ 30 }
    {}

    PerfectTriangle(int a) : IsoscelesTriangle{"Равносторонний треугольник", a, a, 60, 60}
    {}
};

// Четырёхугольник
class Quadrangle : public Figure
{
private:

    void initQuadrangle(int aSide, int bSide, int cSide, int dSide, int AAngle, int BAngle, int CAngle, int DAngle)
    {
        int arrSides[] = { aSide, bSide, cSide, dSide };
        setSides(arrSides);
        int arrAngles[] = { AAngle, BAngle, CAngle, DAngle };
        setAngles(arrAngles);
    }

protected:

    Quadrangle(std::string newName, int aSide, int bSide, int cSide, int dSide, int AAngle, int BAngle, int CAngle, int DAngle) :
        Figure{4, newName}
    {
        initQuadrangle(aSide, bSide, cSide, dSide, AAngle, BAngle, CAngle, DAngle);
    }

public:

    Quadrangle() : Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 }
    {}

    Quadrangle(int aSide, int bSide, int cSide, int dSide, int AAngle, int BAngle, int CAngle, int DAngle) :
        Figure{4, "Четырёхугольник" }
    {
        initQuadrangle(aSide, bSide, cSide, dSide, AAngle, BAngle, CAngle, DAngle);
    }
};

// Прямоугольник
class Rectangle : public Quadrangle
{
protected:

    Rectangle(std::string newName, int a, int b) : Quadrangle{ newName, a, b, a, b, 90, 90, 90, 90 }
    {}

public:

    Rectangle() : Rectangle{ 10, 20 }
    {}

    Rectangle(int a, int b) : Quadrangle{ "Прямоугольник", a, b, a, b, 90, 90, 90, 90 }
    {}
};

// Квадрат
class Quadrate : public Rectangle
{
public:

    Quadrate() : Quadrate{ 20 }
    {}

    Quadrate(int a) : Rectangle{"Квадрат", a, a}
    {}
};

// Параллелограм
class Parallelogram : public Quadrangle
{
public:

    Parallelogram() : Parallelogram{ 20, 30, 30, 40 }
    {}

    Parallelogram(int a, int b, int A, int B) : Quadrangle{ "Параллелограм", a, b, a, b, A, B, A, B }
    {}
};

// Роиб
class Rhombus : public Quadrangle
{
public:

    Rhombus() : Rhombus{ 30, 30, 40 }
    {}

    Rhombus(int a, int A, int B) : Quadrangle{ "Ромб", a, a, a, a, A, B, A, B }
    {}
};

void printInfo(Figure* figure);

int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle triangle;
    RectangularTriangle rectTriangle;
    IsoscelesTriangle isoTriangle;
    PerfectTriangle perfectTriangle;
    Quadrangle quadrangle;
    Rectangle rectangle;
    Quadrate quadrate;
    Parallelogram parallelogram;
    Rhombus rhombus;

    printInfo(&triangle);
    printInfo(&rectTriangle);
    printInfo(&isoTriangle);
    printInfo(&perfectTriangle);
    printInfo(&quadrangle);
    printInfo(&rectangle);
    printInfo(&quadrate);
    printInfo(&parallelogram);
    printInfo(&rhombus);

    system("pause");
    return EXIT_SUCCESS;
}

void printInfo(Figure* figure)
{
    const int arrSize { figure->getSidesCount() };
    int* arrSides = figure->getSides();
    std::cout << figure->getName() << "\nСтороны: ";
    for (int i{}; i < arrSize; ++i)
    {
        char letter = 97 + i;
        std::cout << letter << " = " << arrSides[i] << ' ';
    }

    int* arrAngles = figure->getAngles();
    std::cout << "\n Углы: ";
    for (int i{}; i < arrSize; ++i)
    {
        char letter = 65 + i;
        std::cout << letter << " = " << arrAngles[i] << ' ';
    }
    std::cout << '\n' << std::endl;
}