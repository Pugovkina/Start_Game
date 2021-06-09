
#include "TXLib.h"

void Ball_two_way();
void Ball_draw (int  x, int  y, int r, int  vx, int  vy, COLORREF color, COLORREF fillcolor);
void Ball_way  (int* x, int* y, int r, int* vx, int* vy, int ax, int ay, int dt);
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
         vx1 = 5,   vy1 = 3, r1 = 10,
         ax1 = 0,   ay1 = 1;

     int x2  = 400, y2  = 400,
         vx2 = 8,   vy2 = 5, r2 = 15,
         ax2 = 0,   ay2 = 1;

     int dt = 1;

     while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();
        Ball_draw (x1, y1, r1, vx1, vy1, TX_LIGHTRED,   TX_RED);
        Ball_draw (x2, y2, r2, vx2, vy2, TX_LIGHTGREEN, TX_GREEN);

        Ball_way (&x1, &y1, r1, &vx1, &vy1, ax1, ay1, dt);
        Ball_way (&x2, &y2, r2, &vx2, &vy2, ax2, ay2, dt);

        Ball_Control (&vx1, &vy1);

        txSleep (100);
        }
    }

//-----------------------------------------------------------------

void Ball_draw (int x, int y, int r, int vx, int vy, COLORREF color, COLORREF fillcolor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillcolor);

    txCircle (x, y, r);

    txLine (x, y, x + vx*5, y + vy*5);
    txCircle (x + vx*5, y+ vy*5, 3);
    }

//-----------------------------------------------------------------

void Ball_way (int* x, int* y, int r, int* vx, int* vy, int ax, int ay, int dt)
    {
    *vx = *vx + ax * dt;
    *vy = *vy + ay * dt;

    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    if (*x > 800 - r)
       {
       *vx = - *vx;
       *x  = 800 - r;
       }

    if (*y > 800 - r)
       {
       *vy = - *vy;
       *y = 800 - r;
       }

    if (*x < 0 + r)
       {
       *vx = - *vx;
       *x = 0 + r;
       }

    if (*y < 0 + r)
       {
       *vy = - *vy;
       *y = 0 + r;
       }
    }

//-----------------------------------------------------------------

void Ball_Control (int* vx, int* vy)
   {
   if (txGetAsyncKeyState (VK_RIGHT)) {(*vx) ++;}
   if (txGetAsyncKeyState (VK_LEFT))  {(*vx) --;}
   if (txGetAsyncKeyState (VK_UP))    {(*vy) --;}
   if (txGetAsyncKeyState (VK_DOWN))  { *vy = *vx + 1;}

   if (txGetAsyncKeyState (VK_SPACE)) { *vx = *vy = 0;}
   }
