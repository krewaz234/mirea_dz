#include <iostream>
#include <cmath>

using namespace std;

/**< ПЛОЩАДЬ КРУГА */
double circle_area(double radius)
{
    return acos(-1)*pow(radius, 2);
}

/**< ПЛОЩАДЬ ПРЯМОУГОЛЬНИКА */
 double rectangle_area(double width,  double height)
{
    return width * height;
}

/**< ПЛОЩАДЬ ТРЕУГОЛЬНИКА ЧЕРЕЗ 3 СТОРОНЫ */
/**< ВОЗВРАЩАЕТ -1 ЕСЛИ ТАКОГО ТРЕУГОЛЬНИКА НЕ СУЩЕСТВУЕТ */
double triangle_area(double side1, double side2, double side3)
{
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
        return -1;
    return sqrt(((side1+side2+side3)/2.0)*((side1+side2+side3)/2.0 - side1)*((side1+side2+side3)/2.0 - side2)*((side1+side2+side3)/2.0 - side3));
}

/**< ПЛОЩАДЬ ТРЕУГОЛЬНИКА ЧЕРЕЗ ОСНОВАНИЕ И ВЫСОТУ */
 double triangle_area(double side, double height)
{
    return 0.5*side*height;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование функций площади" << endl
    << "Введите 1, чтобы ввести данные для круга" << endl
    << "Введите 2, чтобы ввести данные для прямоугольника" << endl
    << "Введите 3, чтобы ввести данные для треугольника (три стороны)" << endl
    << "Введите 4, чтобы ввести данные для треугольника (через основание и высоту)" << endl;
    while (true)
    {
        int c;
        cin >> c;
        switch (c)
        {
            case 1:
            {
                double R;
                cout << "Введите радиус: ";
                cin >> R;
                if (R <= 0)
                    cout << "Радиус не может быть отрицательным или равняться нулю" << endl;
                else
                    cout << "Его площадь: " << circle_area(R) << endl;
                break;
            }

            case 2:
            {
                double a, b;
                cout << "Введите две стороны прямоугольника: ";
                cin >> a >> b;
                if (a <= 0 || b <= 0)
                    cout << "Стороны прямоугольника не могут быть отрицательными или равняться нулю" << endl;
                else
                    cout << "Его площадь: " << rectangle_area(a, b) << endl;
                break;
            }

            case 3:
            {
                double a, b, c;
                cout << "Введите три стороны треугольника: ";
                cin >> a >> b >> c;
                if (a <= 0 || b <= 0 || c <= 0)
                    cout << "Сторона треугольника не может быть отрицательной или равняться нулю" << endl;
                else
                {
                    double S = triangle_area(a, b, c);
                    if (S != -1)
                        cout << "Его площадь: " << triangle_area(a, b, c) << endl;
                    else
                        cout << "Такого треугольника не существует" << endl;
                }
                break;
            }

            case 4:
            {
                double a, h;
                cout << "Введите основание и высоту треугольника: ";
                cin >> a >> h;
                if (a <= 0 || h <= 0)
                    cout << "Сторона треугольника или его высота не могут быть отрицательными или равняться нулю" << endl;
                else
                    cout << "Его площадь: " << triangle_area(a, h) << endl;
                break;
            }

            default:
            {
                break;
            }
        }
        cout << "Для следующего теста, введите 1, 2, 3 или 4" << endl;
    }
    return 0;
}
