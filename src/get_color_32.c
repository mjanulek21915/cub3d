#include "main.h"

PIXEL get_color_32(int a, int r, int g, int b)
{
    PIXEL rst;


    rst = a;
    rst = rst<<8;
    rst = rst + r;
    rst = rst<<8;
    rst = rst + g;
    rst = rst<<8;
    rst = rst + b;

    return (rst);
}