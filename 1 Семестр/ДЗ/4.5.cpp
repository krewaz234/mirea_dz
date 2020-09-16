#include <iostream>
#include <cmath>

#define WINDOW_W 50
#define WINDOW_H 20
#define PI acos(-1)

using namespace std;

size_t y_coord_to_pixel(double y)
{
    return (WINDOW_H / 2 + int(y * WINDOW_H / 2));
}

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

void display_window(char **window)
{
    for (size_t i = 0; i < WINDOW_H; ++i)
    {
        for (size_t j =0 ; j < WINDOW_W; ++j)
            cout <<  window[i][j];
        cout << endl;
    }
}

void draw_graph(char **window)
{
    double step_x = (4*PI) / (double)WINDOW_W;
    double step_y = 2.0 / (double)WINDOW_H;
    double cur_x_coord = -2*PI;
    for (size_t i = 0; i < WINDOW_W; ++i)
    {
        double y = sin(cur_x_coord);
        size_t y_pixel = y_coord_to_pixel(y);
        window[WINDOW_H - y_pixel][i] = '*';
        cur_x_coord += 4*PI / (double)WINDOW_W;
    }
}

int main()
{
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
