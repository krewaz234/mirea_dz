#include <iostream>
#include <cmath>

//можете попробовать поиграться с размерами, на больших выглядит красиво
#define WINDOW_W 81
#define WINDOW_H 31
//вычислять число пи таким образом точнее, потому что его вычисляет сам компьютер
#define PI acos(-1)

using namespace std;

//перевод y-координаты графика y=sin(x) y-координате в матрице из char
int y_coord_to_pixel(double y)
{
    //вершины
    if (fabs(y) >= 0.9)
    {
        if (y >= 0.99)
            return 0;
        if (y <= -0.99)
            return WINDOW_H - 1;
        if (y >= 0.9)
            return 1;
        if (y <= -0.9)
            return WINDOW_H - 2;
    }

    return WINDOW_H - 1 - ((WINDOW_H - 1) / 2 + round((double(WINDOW_H - 1) / 2.0)*y));
}

//просто отрисовка координатных осей
void draw_axis(char **window)
{
    int center_x = (WINDOW_W - 1) / 2;
    int center_y = (WINDOW_H - 1) / 2;

    window[0][center_x] = '^';
    window[0][center_x + 1] = 'y';

    for (size_t i = 1; i < WINDOW_H; ++i)
        window[i][center_x] = '|';

    for (size_t i = 0; i < WINDOW_W - 1; ++i)
        window[center_y][i] = '-';
    window[center_y][WINDOW_W - 1] = '>';
    window[center_y - 1][WINDOW_W - 1] = 'x';
}

//вывод матрицы на экран
void display_window(char **window)
{
    for (size_t i = 0; i < WINDOW_H; ++i)
    {
        for (size_t j =0 ; j < WINDOW_W; ++j)
            cout <<  window[i][j];
        cout << endl;
    }
}

//отрисовка самого графика
void draw_graph(char **window)
{
    double step_x = (4*PI) / (double)WINDOW_W; //шаг по x (как в задаче "табуляция")
    double cur_x_coord = -2*PI; //x-координата на текущем шаге отрисовки графика
    for (size_t i = 0; i < WINDOW_W; ++i)
    {
        double y = sin(cur_x_coord);
        int y_pixel = y_coord_to_pixel(y);
        window[y_pixel][i] = '*';
        cur_x_coord += step_x;
    }
}

int main()
{
    //инициализация матрицы в которой у нас все будет рисоваться
    char **window = new char*[WINDOW_H];
    for (size_t i = 0; i < WINDOW_H; ++i)
        window[i] = new char[WINDOW_W];
    for (size_t i = 0; i < WINDOW_H; ++i)
        for (size_t j = 0; j < WINDOW_W; ++j)
            window[i][j] = ' ';

    draw_axis(window);
    draw_graph(window);
    display_window(window);
    return 0;
}
