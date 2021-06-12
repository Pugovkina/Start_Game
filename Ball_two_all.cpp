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
void Ball_draw (int  x, int  y, int  vx, int  vy, int r, COLORREF color, COLORREF fillcolor);
void Ball_way  (int* x, int* y, int* vx, int* vy, int r, int ax, int ay, int dt);
void Ball_Control (int* vx, int* vy);
void Znachenia_out (int* znach, int x, int y);

double Distanse (double x1, double y1, double x2, double y2);
int Koli4stvo_zhizni (int* ydar);

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

struct Ball
    {
    int  x,  y,
        vx, vy;

    int radius;
    };

//-----------------------------------------------------------------

void Ball_two_way()
    {
     int ydar = 0;

     Ball ball1 = {.x = 100, .y = 100, .vx = 5, .vy = 3, .radius = 15};

     Ball ball2 = {400, 400, 8, 5, 15};

     /*int x1  = 100, y1  = 100,
         vx1 = 5,   vy1 = 3, r1 = 15,*/

    /* int x2  = 400, y2  = 400,
         vx2 = 8,   vy2 = 5, r2 = 15,*/

     int ax = 2, ay = 1;

     int dt = 1;

     while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();

        Pole_for_game();

        Ball_draw (ball1, RGB (170, 170,   0), RGB (255, 255,  15));
        Ball_draw (ball2, RGB (128,   0, 255), RGB (190, 130, 255));

        Ball_way (&ball1, ax, ay, dt);
        Ball_way (&ball2, ax, ay, dt);

        double dist = Distanse (x1, y1, x2, y2);

        if (dist <= r1 + r2) ydar = ydar + 1;

        Znachenia_out (&ydar, 250, 28);

        int zhizn = Koli4stvo_zhizni (&ydar);

        Znachenia_out (&zhizn, 250, 550);

        if (zhizn == 0)
            {
            Text_out (70, 230, 50, "Igra zakonchena");
            break;
            }

        Ball_Control (&vx1, &vy1);

        txSleep (50);
        }
    }

//-----------------------------------------------------------------

void Ball_draw (int x, int y, int vx, int vy, int r, COLORREF color, COLORREF fillcolor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillcolor);

    txCircle (x, y, r);

    txLine (x, y, x + vx*3, y + vy*3);
    txCircle (x + vx*3, y+ vy*3, 2);
    }

//-----------------------------------------------------------------

void Ball_way (int* x, int* y, int* vx, int* vy, int r, int ax, int ay, int dt)
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

int Koli4stvo_zhizni (int* ydar)
    {
    int zhizn = 5;
    int k = zhizn;

    if (*ydar/3 == 0) k --;

    return  zhizn;
    }

//-----------------------------------------------------------------

//-----------------------------------------------------------------

double Distanse (double x1, double y1, double x2, double y2)
    {
    double dist = sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    return dist;
    }

//-----------------------------------------------------------------
