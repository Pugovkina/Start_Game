//{===========================================================================
//! @file       Ball_two_all.cpp
//!
//! @brief
//!            Tatiana Pugovkina,
//!             the first game
//!               sity Omsk
//}===========================================================================

#include "TXLib.h"

void Pole_for_game ();
void Text_out (int x, int y, int size_text, char text[24]);
void Ball_two_way();
void Ball_draw (int  x, int  y, int r, int  vx, int  vy, COLORREF color, COLORREF fillcolor);
void Ball_way  (int* x, int* y, int r, int* vx, int* vy, int ax, int ay, int dt);
void Ball_Control (int* vx, int* vy);
void Znachenia_out (int* znach, int x, int y);

double Distanse (double x1, double y1, double x2, double y2);

//-----------------------------------------------------------------

int main()
    {
    txCreateWindow (400, 600);

    Pole_for_game();

    Ball_two_way();

    return 0;
    }

//-----------------------------------------------------------------

void Pole_for_game ()
    {
    txSetFillColor (RGB (168, 255, 211));
    txClear ();

    txSetColor     (RGB (0, 213, 106));
    txSetFillColor (RGB (0, 174,  87));
    txRectangle (0,                   0, txGetExtentX(),             80);
    txRectangle (0, txGetExtentY() - 60, txGetExtentX(), txGetExtentY());

    Text_out (20,  28, 30, "Koli4stvo stolknovenii: ");
    Text_out (20, 550, 30, "Koli4stvo zhizni: ");
    }

//-----------------------------------------------------------------

void Text_out (int x, int y, int size_text, char text[25])
    {
    txSetColor (TX_BLACK);

    txSelectFont ("Arial", size_text);

    txTextOut (x,  y, text);
    }

//-----------------------------------------------------------------

void Znachenia_out (int* znach, int x, int y)
    {
    char strZnach[10] = "";
    sprintf (strZnach, "%d", *znach);

    txSetColor (TX_BLACK);
    txSelectFont ("Arial", 30);
    txTextOut (x,  y, strZnach);
    }


//-----------------------------------------------------------------

void Ball_two_way()
    {
     int ydar = 0;

     int x1  = 100, y1  = 100,
         vx1 = 5,   vy1 = 3, r1 = 15,
         ax1 = 0,   ay1 = 1;

     int x2  = 400, y2  = 400,
         vx2 = 8,   vy2 = 5, r2 = 15,
         ax2 = 0,   ay2 = 1;

     int dt = 1;

     while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();

        Pole_for_game();

        Ball_draw (x1, y1, r1, vx1, vy1, RGB (170, 170,   0), RGB (255, 255,  15));
        Ball_draw (x2, y2, r2, vx2, vy2, RGB (128,   0, 255), RGB (190, 130, 255));

        Ball_way (&x1, &y1, r1, &vx1, &vy1, ax1, ay1, dt);
        Ball_way (&x2, &y2, r2, &vx2, &vy2, ax2, ay2, dt);

        double dist = Distanse (x1, y1, x2, y2);

        if (dist <= r1 + r2) ydar = ydar + 1;

        Znachenia_out (&ydar, 250, 28);

        Ball_Control (&vx1, &vy1);

        txSleep (50);
        }

    Text_out (70, 230, 50, "Igra zakonchena");
    }

//-----------------------------------------------------------------

void Ball_draw (int x, int y, int r, int vx, int vy, COLORREF color, COLORREF fillcolor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillcolor);

    txCircle (x, y, r);

    txLine (x, y, x + vx*3, y + vy*3);
    txCircle (x + vx*3, y+ vy*3, 2);
    }

//-----------------------------------------------------------------

void Ball_way (int* x, int* y, int r, int* vx, int* vy, int ax, int ay, int dt)
    {
    *vx = *vx + ax * dt;
    *vy = *vy + ay * dt;

    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    if (*x > 400 - r)
       {
       *vx = - *vx;
       *x  = 400 - r;
       }

    if (*y > 540 - r)
       {
       *vy = - *vy;
       *y = 540 - r;
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
   if (txGetAsyncKeyState (VK_RIGHT)) (*vx) ++;
   if (txGetAsyncKeyState (VK_LEFT))  (*vx) --;
   if (txGetAsyncKeyState (VK_UP))    (*vy) --;
   if (txGetAsyncKeyState (VK_DOWN))   *vy = *vx + 1;

   if (txGetAsyncKeyState (VK_SPACE))  *vx = *vy = 0;
   }

//-----------------------------------------------------------------

//void Koli4stvo_zhizni ()
//    {
//    Zhizn = 0;

//    }

//-----------------------------------------------------------------

//-----------------------------------------------------------------

double Distanse (double x1, double y1, double x2, double y2)
    {
    double dist = sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    return dist;
    }

//-----------------------------------------------------------------
