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

protected:

    Figure(std::string str) : name{ str }
    {}

public:

    std::string getName() { return name; }

    Figure() = default;

    Figure(std::string str) : name{ str }
    {}

    virtual std::string toString() = 0;
};

// Треугольник
class Triangle : public Figure
{
private:

    int aSide{ 10 };
    int bSide{ 20 };
    int cSide{ 30 };

    int aAngle{ 50 };
    int bAngle{ 60 };
    int cAngle{ 70 };

protected:

    int getASide() { return aSide; }
    int getBSide() { return bSide; }
    int getCSide() { return cSide; }

    int getAAngle() { return aAngle; }
    int getBAngle() { return bAngle; }
    int getCAngle() { return cAngle; }

    Triangle(std::string newName, int a, int b, int c, int A, int B, int C) :
        Figure(newName), aSide{ a }, bSide{ b }, cSide{ c }, aAngle{ A }, bAngle{ B }, cAngle{ C }
    {}

public:

    Triangle() : Triangle{ 10, 20, 30, 50, 60, 70 }
    {}

    Triangle(int a, int b, int c, int A, int B, int C) :
        Figure{ "Треугольник" }, aSide{a}, bSide{b}, cSide{c}, aAngle{A}, bAngle{B}, cAngle{C}
    {}

    std::string data()
    {
        return "Стороны: a = " + std::to_string(getASide()) + " b = " + std::to_string(getBSide()) + " c = " + std::to_string(getCSide()) +
            "\nУглы: A = " + std::to_string(getAAngle()) + " B = " + std::to_string(getBAngle()) + " C = " + std::to_string(getCAngle());
    }

    virtual std::string toString() override
    {
        return getName() + ":\n" + data();
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

    int aSide{ 10 };
    int bSide{ 20 };
    int cSide{ 30 };
    int dSide{ 40 };

    int aAngle{ 50 };
    int bAngle{ 60 };
    int cAngle{ 70 };
    int dAngle{ 80 };

protected:

    int getASide() { return aSide; }
    int getBSide() { return bSide; }
    int getCSide() { return cSide; }
    int getDSide() { return dSide; }

    int getAAngle() { return aAngle; }
    int getBAngle() { return bAngle; }
    int getCAngle() { return cAngle; }
    int getDAngle() { return dAngle; }

    Quadrangle(std::string newName, int a, int b, int c, int d, int A, int B, int C, int D) :
        Figure(newName), aSide{ a }, bSide{ b }, cSide{ c }, dSide{ d }, aAngle{ A }, bAngle{ B }, cAngle{ C }, dAngle{ D }
    {}

public:

    Quadrangle() : Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 }
    {}

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) :
        Figure{ "Четырёхугольник" }, aSide{a}, bSide{b}, cSide{c}, dSide{d}, aAngle{A}, bAngle{B}, cAngle{C}, dAngle{D}
    {}

    std::string data()
    {
        return "Стороны: a = " + std::to_string(getASide()) + " b = " + std::to_string(getBSide()) + " c = " + std::to_string(getCSide()) + " d = " + std::to_string(getDSide()) + 
            "\nУглы: A = " + std::to_string(getAAngle()) + " B = " + std::to_string(getBAngle()) + " C = " + std::to_string(getCAngle()) + " D = " + std::to_string(getDAngle());
    }

    virtual std::string toString() override
    {
        return getName() + ":\n" + data();
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
    std::cout << figure->toString() << '\n' << std::endl;
}