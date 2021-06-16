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
void Text_out (int x, int y, int size_text, const char text[24]);
void Ball_two_way();

void Ball_draw (struct Ball ball, COLORREF color, COLORREF fillcolor);

void Ball_way  (struct Ball *, double ax, double ay, double dt);

void Ball_Control (double* vx, double* vy);
void Znachenia_out (int* znach, int x, int y);

double Distanse (double x1, double y1, double x2, double y2);
int Koli4stvo_zhizni (int* ydar);

//-----------------------------------------------------------------

struct Ball
    {
    double  x,  y,
           vx, vy;

    int    radius;
    };

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

void Text_out (int x, int y, int size_text, const char text[])
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
     int n_ydar = 0;

     struct Ball ball1 = {100, 100, 5, 3, 15};

     struct Ball ball2 = {400, 400, 8, 5, 15};

     double ax = 0, ay = 0;

     double dt = 1;

     bool old_ydar = false;

     while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();

        Pole_for_game();

        Ball_draw (ball1, RGB (170, 170,   0), RGB (255, 255,  15));
        Ball_draw (ball2, RGB (128,   0, 255), RGB (190, 130, 255));

        Ball_way (&ball1, ax, ay, dt);
        Ball_way (&ball2, ax, ay, dt);

        double dist = Distanse (ball1.x, ball1.y, ball2.x, ball2.y);

        bool ydar = false;

        if (dist <= ball1.radius + ball2.radius) ydar = true;

        if (old_ydar == false && ydar == true) n_ydar = n_ydar + 1;

        old_ydar = ydar;

        Znachenia_out (&n_ydar, 250, 28);

       /* int zhizn = Koli4stvo_zhizni (&ydar);

        Znachenia_out (&zhizn, 250, 550);

        if (zhizn == 0)
            {
            Text_out (70, 230, 50, "Igra zakonchena");
            break;
            }  */

        Ball_Control (&ball1.vx, &ball1.vy);

        txSleep (50);
        }
    }

//-----------------------------------------------------------------

void Ball_draw (struct Ball ball, COLORREF color, COLORREF fillcolor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillcolor);

    txCircle (ball.x, ball.y, ball.radius);

    txLine (ball.x, ball.y, ball.x + ball.vx*3, ball.y + ball.vy*3);

    txCircle (ball.x + ball.vx*3, ball.y+ ball.vy*3, 2);
    }

//-----------------------------------------------------------------

void Ball_way (struct Ball *ball, double ax, double ay, double dt)
    {
    ball -> vx = ball -> vx + ax * dt;
    ball -> vy = ball -> vy + ay * dt;

    ball -> x = ball -> x + (ball -> vx) * dt;
    ball -> y = ball -> y + (ball -> vy) * dt;

    if (ball -> x > 400 - (ball -> radius))
       {
       ball -> vx = - (ball -> vx);
       ball -> x  = (400 - ball -> radius) - (ball -> x - (400 - ball -> radius)) * 2;
       }

    if (ball -> y > 540 - (ball -> radius))
       {
       ball -> vy = - (ball -> vy);
       ball -> y = (540 - ball -> radius) - (ball -> y - (540 - ball -> radius)) * 2;
       }

    if (ball -> x < 0 + (ball -> radius))
       {
       ball -> vx = - (ball -> vx);
       ball -> x = (0 + (ball -> radius)) + ((0 + (ball -> radius)) - (ball -> x)) * 2;
       }

    if (ball -> y < 80 + (ball -> radius))
       {
       ball -> vy = - (ball -> vy);
       ball -> y = (80 + (ball -> radius)) + ((80 + (ball -> radius)) - (ball -> y)) * 2;
       }
    }

//-----------------------------------------------------------------

void Ball_Control (double* vx, double* vy)
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
