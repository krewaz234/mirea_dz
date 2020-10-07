//по моему мнению, одна из самых сложных задач во всей 4 домашке
#include <iostream>
#include <cmath>

//можете попробовать поиграться с размерами, на больших выглядит красиво
#define WINDOW_W 50
#define WINDOW_H 20
//вычислять число пи таким образом точнее, потому что его вычисляет сам компьютер
#define PI acos(-1)

using namespace std;

//перевод y-координаты графика y=sin(x) y-координате в матрице из char
int y_coord_to_pixel(double y)
{
    //как я вывел эту формулу?
    //высота нашей матрицы пополам - это точка 0 по оси y
    //к ней мы прибавляем округленную (по понятным причинам) высоту деленную на 2
    //(от высоты отнимаю 2, иначе происходит выход за границы матрицы)
    //и умноженную на y-координату а-ля "растяжение до нужных размеров"

    //эта вся ерундистика отнимается от высоты матрицы потому что y координата у нас идет вниз
    //(просто потому что у матрицы нет y координаты, это строка)
    return WINDOW_H - (WINDOW_H / 2 + round(y * floor(double(WINDOW_H-2) / 2.0)));
}

//просто отрисовка координатных осей
void draw_axis(char **window)
{
    int center_x = WINDOW_W / 2;
    int center_y = WINDOW_H / 2;

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
