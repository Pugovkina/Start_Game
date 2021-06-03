
#include "TXLib.h"

void Ball_one(int x, int y, int vx, int vy, int dt);
void Ball_two(int x, int y, int vx, int vy, int dt);

//-----------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 800);

    Ball_one(100, 100, 5, 3, 1);
    Ball_two(400, 400, 5, 3, 1);

    txSleep (1000);

    return 0;
    }

//-----------------------------------------------------------------

void Ball_one(int x, int y, int vx, int vy, int dt)
    {
     txSetColor (TX_LIGHTGREEN, 2);
     txSetFillColor (TX_GREEN);

     while (! txGetAsyncKeyState ('F'))
        {
        txSetColor (RGB (x, y, 128), 2);
        txSetFillColor (RGB (x/3, y/3, 128));

        txCircle (x, y, 20);

        x += vx * dt;
        y += vy * dt;

        if (x > 800)
            {
            vx = -vx;
            x = 800;
            }

        if (y > 800)
            {
            vy = -vy;
            y = 800;
            }

        if (x < 0)
            {
            vx = -vx;
            x = 0;
            }

        if (y < 0)
            {
            vy = -vy;
            y = 0;
            }

        if (txGetAsyncKeyState (VK_RIGHT)) vx++;
        if (txGetAsyncKeyState (VK_LEFT))  vx--;
        if (txGetAsyncKeyState (VK_UP))    vy--;
        if (txGetAsyncKeyState (VK_DOWN))  vy++;

        if (txGetAsyncKeyState (VK_SPACE)) vx = vy = 0;

        txSleep (10);
        }
    }

//-----------------------------------------------------------------

void Ball_two(int x, int y, int vx, int vy, int dt)
    {
     txSetColor (TX_RED, 2);
     txSetFillColor (TX_YELLOW);

     while (! txGetAsyncKeyState ('B'))
        {
        txCircle (x, y, 20);

        x += vx * dt;
        y += vy * dt;

        if (x > 800)
            {
            vx = -vx;
            x = 800;
            }

        if (y > 800)
            {
            vy = -vy;
            y = 800;
            }

        if (x < 0)
            {
            vx = -vx;
            x = 0;
            }

        if (y < 0)
            {
            vy = -vy;
            y = 0;
            }

        txSleep (10);
        }
    }
