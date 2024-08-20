/*
В этом задании вы построите первую простую иерархию классов для заданной предметной области.

Предметная область выглядит следующим образом: есть сущность фигура. Фигуры бывают двух типов: треугольник и четырёхугольник. У фигуры есть количество сторон. Для неизвестной фигуры будем считать это количество равным нулю. У треугольника три стороны, у четырёхугольника четыре стороны. У любой фигуры мы хотим узнавать количество её сторон, но мы не должны быть способны изменить количество сторон для заданной фигуры извне.

Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонстрируйте их работу: создайте по одному экземпляру каждого класса и выведите информацию о количестве его сторон на консоль.

Пример работы программы
*/

#include <iostream>
#include <clocale>
#include <string>

// Базовый класс
class Figure
{
private:

    int sidesCount{};
    std::string name{ "Фигура" };

protected:

    Figure(int value, std::string str) : sidesCount{ value }, name{ str }
    {}

public:

    Figure() = default;

    std::string toString()
    {
        return name + ": " + std::to_string(sidesCount);
    }
};

class Triangle : public Figure
{
protected:


    Triangle(int value) : Figure{ value, "Треугольник" }
    {}

public:

    Triangle() : Triangle{3}
    {}
};

class Quadrangle : public Figure
{
protected:

    Quadrangle(int value) : Figure{ value, "Четырёхугольник" }
    {}

public:

    Quadrangle() : Quadrangle(4)
    {}
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:\n";
    std::cout << figure.toString() << std::endl
        << triangle.toString() << std::endl
        << quadrangle.toString() << std::endl;

    system("pause");
    return EXIT_SUCCESS;
}
