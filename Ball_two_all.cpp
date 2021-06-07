
#include "TXLib.h"

void Ball_two_way();
void Ball_draw (int  x, int  y, int  vx, int  vy, COLORREF color, COLORREF fillcolor);
void Ball_way  (int* x, int* y, int* vx, int* vy, int ax, int ay, int dt);
void Ball_Control (int* vx, int* vy);

//-----------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 800);

    Ball_two_way();

    return 0;
    }

//-----------------------------------------------------------------

void Ball_two_way()
    {
     int x1  = 100, y1  = 100,
         vx1 = 5,   vy1 = 3,
         ax1 = 0,   ay1 = 1;

     int x2  = 400, y2  = 400,
         vx2 = 8,   vy2 = 5,
         ax2 = 0,   ay2 = 1;

     int dt = 1;

     while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        Ball_draw (x1, y1, vx1, vy1, TX_LIGHTRED,   TX_RED);
        Ball_draw (x2, y2, vx2, vy2, TX_LIGHTGREEN, TX_GREEN);

        Ball_way (&x1, &y1, &vx1, &vy1, ax1, ay1, dt);
        Ball_way (&x2, &y2, &vx2, &vy2, ax2, ay2, dt);

        Ball_Control (&vx1, &vy1);

        txSleep (10);
        }
    }

//-----------------------------------------------------------------

void Ball_draw (int x, int y, int vx, int vy, COLORREF color, COLORREF fillcolor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillcolor);

    txCircle (x, y, 20);

    txLine (x, y, x + vx*5, y + vy*5);
    txCircle (x + vx*5, y+ vy*5, 3);
    }

//-----------------------------------------------------------------

void Ball_way (int* x, int* y, int* vx, int* vy, int ax, int ay, int dt)
    {
    *vx = *vx + ax * dt;
    *vy = *vy + ay * dt;

    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    if (*x > 800)
       {
       *vx = - *vx;
       *x  = 800;
       }

    if (*y > 800)
       {
       *vy = - *vy;
       *y = 800;
       }

    if (*x < 0)
       {
       *vx = - *vx;
       *x = 0;
       }

    if (*y < 0)
       {
       *vy = - *vy;
       *y = 0;
       }
    }

//-----------------------------------------------------------------

void Ball_Control (int* vx, int* vy)
   {
   if (txGetAsyncKeyState (VK_RIGHT)) (*vx)++;
   if (txGetAsyncKeyState (VK_LEFT))  (*vx)--;
   if (txGetAsyncKeyState (VK_UP))    (*vy)--;
   if (txGetAsyncKeyState (VK_DOWN))  (*vy)++;

   if (txGetAsyncKeyState (VK_SPACE)) *vx = *vy = 0;
   }
