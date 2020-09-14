#include <iostream>

using namespace std;

/**< ПЛОЩАДЬ КРУГА */
double circle_area(double radius)
{
    return acos(-1)*pow(radius, 2);
}

/**< ПЛОЩАДЬ ПРЯМОУГОЛЬНИКА */
double rectangle_area(double width, double height)
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
    /**< INSERT CODE HERE */
    return 0;
}
