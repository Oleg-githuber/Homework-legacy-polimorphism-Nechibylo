/*
В этом задании вы добавите в вашу иерархию классов больше функциональности.

Теперь ваши фигуры должны уметь немного больше:

выводить информацию о себе;
проверять правильность своих данных.
Ваши фигуры:

фигура (количество сторон равно 0);
треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равны, углы A и C равны);
равносторонний треугольник (все стороны равны, все углы равны 60);
четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
квадрат (все стороны равны, все углы равны 90);
параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
ромб (все стороны равны, углы A,C и B,D попарно равны).
Вы должны иметь возможность попросить фигуру вывести информацию о себе на консоль, а также узнать, является ли фигура правильной, то есть выполняются ли условия, указанные в списке выше.

Информация о фигуре включает в себя:

название фигуры;
количество сторон;
длины её сторон, если есть;
величины её углов, если есть;
является ли фигура правильной.
Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонструйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о фигурах.

Реализуйте методы вывода на консоль и проверки правильности фигуры с помощью виртуальных функций и переопределений. Используйте вызов базовой версии метода.

Ваша задача — работать с экземплярами дочерних классов полиморфно, то есть с помощью указателя на базовый класс.
*/

#include <iostream>
#include <clocale>
#include <string>

class Figure
{
private:

    std::string name{"Фигура"};
    int sidesCount{};
    int sides[6] = {};
    int angles[6] = {};

protected:

    virtual bool isCorrect()
    {
        if (!sidesCount) return true;
        return false;
    }

protected:

    Figure(int value, std::string str) : sidesCount{ value }, name{ str }
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

    int anglesSum()
    {
        int sum{};
        for (int i{}; i < getSidesCount(); ++i)
        {
            sum += getAngles()[i];
        }
        return sum;
    }

public:

    std::string getName() { return name; }

    int getSidesCount() { return sidesCount; }

    int* getSides() { return sides; }

    int* getAngles() { return angles; }

    Figure() = default;

    std::string toString()
    {
        std::string info = getName() + ":\n" + ((isCorrect()) ? ("Правильная") : ("Неправильная")) + "\nКоличество сторон: " + std::to_string(getSidesCount());
        if (getSidesCount())
        {
            info += "\nСтороны: ";
            for (int i{}; i < getSidesCount(); ++i)
            {
                char letter = 97 + i;
                info = info + letter + " = " + std::to_string(getSides()[i]) + ' ';
            }
            info += "\nУглы: ";
            for (int i{}; i < getSidesCount(); ++i)
            {
                char letter = 65 + i;
                info = info + letter + " = " + std::to_string(getAngles()[i]) + ' ';
            }
        }
        
        return info + "\n\n";
    }
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
    virtual bool isCorrect() override
    {
        if (getSidesCount() == 3 && anglesSum() == 180)
        {
            return true;
        }
        return false;
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
        Figure{ 3, "Треугольник" }
    {
        initTriangle(aSide, bSide, cSide, AAngle, BAngle, CAngle);
    }
};

// Прямоугольный треугольник
class RectangularTriangle : public Triangle
{
protected:
    bool isCorrect() override
    {
        if (Triangle::isCorrect() && getAngles()[getSidesCount() - 1])
        {
            return true;
        }
        return false;
    }
public:

    RectangularTriangle() : RectangularTriangle{ 10, 20, 30, 50, 60 }
    {}

    RectangularTriangle(int a, int b, int c, int A, int B) : Triangle{ "Прямоугольный треугольник", a, b, c, A, B, 90 }
    {}
};

// Равнобедренный треугольник
class IsoscelesTriangle : public Triangle
{
protected:

    IsoscelesTriangle(std::string newName, int a, int b, int A, int B) : Triangle{ newName, a, b, a, A, B, A }
    {}

    virtual bool isCorrect() override
    {
        if (Triangle::isCorrect() && (getSides()[0] == getSides()[getSidesCount() - 1]) && (getAngles()[0] == getAngles()[getSidesCount() - 1]))
        {
            return true;
        }
        return false;
    }

public:

    IsoscelesTriangle() : IsoscelesTriangle{ 10, 20, 50, 60 }
    {}

    IsoscelesTriangle(int a, int b, int A, int B) : Triangle{ "Равнобедренный треугольник", a, b, a, A, B, A }
    {}
};

// Равосторонний треугольник
class PerfectTriangle : public IsoscelesTriangle
{
protected:

    bool isCorrect() override
    {
        if (IsoscelesTriangle::isCorrect() && (getSides()[0] == getSides()[1]) && (getAngles()[0] == getAngles()[1]))
        {
            return true;
        }
        return false;
    }

public:

    PerfectTriangle() : PerfectTriangle{ 30 }
    {}

    PerfectTriangle(int a) : IsoscelesTriangle{ "Равносторонний треугольник", a, a, 60, 60 }
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
        Figure{ 4, newName }
    {
        initQuadrangle(aSide, bSide, cSide, dSide, AAngle, BAngle, CAngle, DAngle);
    }

    virtual bool isCorrect() override
    {
        if ((getSidesCount() == 4) && (anglesSum() == 360))
        {
            return true;
        }
        return false;
    }

public:

    Quadrangle() : Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 }
    {}

    Quadrangle(int aSide, int bSide, int cSide, int dSide, int AAngle, int BAngle, int CAngle, int DAngle) :
        Figure{ 4, "Четырёхугольник" }
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

    virtual bool areAnglesRect()
    {
        for (int i{}; i < getSidesCount(); ++i)
        {
            if (getAngles()[i] != 90) return false;
        }
        return true;
    }

    virtual bool isCorrect() override
    {
        if (Quadrangle::isCorrect() && (getSides()[0] == getSides()[2]) && (getSides()[1] == getSides()[3]) && areAnglesRect())
        {
            return true;
        }
        return false;
    }

public:

    Rectangle() : Rectangle{ 10, 20 }
    {}

    Rectangle(int a, int b) : Quadrangle{ "Прямоугольник", a, b, a, b, 90, 90, 90, 90 }
    {}
};

// Квадрат
class Quadrate : public Rectangle
{
protected:

    bool areSisedEqual()
    {
        for (int i{1}; i < getSidesCount(); ++i)
        {
            if (getSides()[0] != getSides()[i])
            {
                return false;
            }
        }
        return true;
    }

    bool isCorrect() override
    {
        if (Rectangle::isCorrect() && areSisedEqual())
        {
            return true;
        }
        return false;
    }

public:

    Quadrate() : Quadrate{ 20 }
    {}

    Quadrate(int a) : Rectangle{ "Квадрат", a, a }
    {}
};

// Параллелограм
class Parallelogram : public Quadrangle
{

protected:
    bool isCorrect() override
    {
        if (Quadrangle::isCorrect() && (getSides()[0] == getSides()[2]) && (getSides()[1] == getSides()[3]) && (getAngles()[0] == getAngles()[2]) && (getAngles()[1] == getAngles()[3]))
        {
            return true;
        }
        return false;
    }
public:

    Parallelogram() : Parallelogram{ 20, 30, 30, 40 }
    {}

    Parallelogram(int a, int b, int A, int B) : Quadrangle{ "Параллелограм", a, b, a, b, A, B, A, B }
    {}
};

// Роиб
class Rhombus : public Quadrangle
{
protected:

    bool areSidesEqual()
    {
        for (int i{ 1 }; i < getSidesCount(); ++i)
        {
            if (getSides()[0] != getSides()[i])
            {
                return false;
            }
        }
        return true;
    }

    bool isCorrect() override
    {
        if (Quadrangle::isCorrect() && areSidesEqual() && (getAngles()[0] == getAngles()[2]) && (getAngles()[1] == getAngles()[3]))
        {
            return true;
        }
        return false;
    }

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

    Figure figure;
    Triangle triangle;
    RectangularTriangle rectTriangle{10, 20, 30, 50, 40};
    IsoscelesTriangle isoTriangle;
    PerfectTriangle perfectTriangle;
    Quadrangle quadrangle;
    Rectangle rectangle;
    Quadrate quadrate;
    Parallelogram parallelogram;
    Rhombus rhombus;

    std::cout << figure.toString();
    std::cout << triangle.toString();
    std::cout << rectTriangle.toString();
    std::cout << isoTriangle.toString();
    std::cout << perfectTriangle.toString();
    std::cout << quadrangle.toString();
    std::cout << rectangle.toString();
    std::cout << quadrate.toString();
    std::cout << parallelogram.toString();
    std::cout << rhombus.toString();

    system("pause");
    return EXIT_SUCCESS;
}