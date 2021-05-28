
#include "TXLib.h"

void Ball_Way();

int main()
    {
    txCreateWindow (800, 800);

    Ball_Way();

    return 0;
    }

void Ball_Way()
    {
     int x  = 100, y  = 100,
         vx = 5,   vy = 3;

     int dt = 1;

     txSetColor (TX_LIGHTGREEN, 2);
     txSetFillColor (TX_GREEN);

     while (! txGetAsyncKeyState (VK_ESCAPE))
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

        txSleep (500);
        }
    }
