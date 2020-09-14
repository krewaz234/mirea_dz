#include <iostream>

using namespace std;

/**< ПЛОЩАДЬ КРУГА */
unsigned double circle_area(unsigned double radius)
{
    return acos(-1)*pow(radius, 2);
}

/**< ПЛОЩАДЬ ПРЯМОУГОЛЬНИКА */
unsigned double rectangle_area(unsigned double width, unsigned double height)
{
    return width * height;
}

/**< ПЛОЩАДЬ ТРЕУГОЛЬНИКА ЧЕРЕЗ 3 СТОРОНЫ */
/**< ВОЗВРАЩАЕТ -1 ЕСЛИ ТАКОГО ТРЕУГОЛЬНИКА НЕ СУЩЕСТВУЕТ */
double triangle_area(unsigned double side1, unsigned double side2, unsigned double side3)
{
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
        return -1;
    return sqrt(((side1+side2+side3)/2.0)*((side1+side2+side3)/2.0 - side1)*((side1+side2+side3)/2.0 - side2)*((side1+side2+side3)/2.0 - side3));
}

/**< ПЛОЩАДЬ ТРЕУГОЛЬНИКА ЧЕРЕЗ ОСНОВАНИЕ И ВЫСОТУ */
unsigned double triangle_area(unsigned double side, unsigned double height)
{
    return 0.5*side*height;
}

int main()
{
    /**< INSERT CODE HERE */
    return 0;
}
