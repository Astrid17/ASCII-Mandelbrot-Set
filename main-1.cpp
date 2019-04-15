#ifndef TESTS
#include <iostream>
#include "asciiimage.h"

using namespace std;

int main()
{

     myAscii hello(3, 5);
    hello.show();

    myAscii mandelbrot(80, 25);

    double zahl1 = -3;
    double zahl2 = -1.5;
    double zahl3 = 1;
    double zahl4 = 1.5;
    int size = 50;

    //x und y Koordinate im imaginaeren Bild
    double res1;
    double res2;

    //Skaliere fuer jeden Punkt der Computergrafik den dazu gehoerigen Punkt der  Grafik
    for (int i = 0; i < 80; i++)
    {
        res1 = zahl1 + (zahl2 - zahl1) / ((double)80) * (double)i;
        for (int z = 0; z < 25; z++)
        {
            res2 = zahl3 + (zahl4 - zahl3) / ((double)25) * (double)z;

            double komplex_nr1 = 0;
            double komplex_nr2 = 0;
            int j;

            //Berechnung der Farbwerte
            for (i = 0; i < size; ++i)
            {
                // calculate next iteration
                // In the next row we calculate komplex_nr1 * komplex_nr2 + res1 and check whether |z| > 2
                double nextkomplex_nr1 = komplex_nr1 * komplex_nr1 - komplex_nr2 * komplex_nr2 + res1;
                double nextkomplex_nr2 = 2 * komplex_nr1 * komplex_nr2 + res2;
                
               /* if (nextkomplex_nr1 * nextkomplex_nr1 + nextkomplex_nr2 * nextkomplex_nr2 > 4)
                {
                    // TODO: set pixel to i % 70
                    // Insert here code to draw
                    //cout << "Pixel: " << t << "," << s << " ist " << i << "|";
                    break;
                }*/
                komplex_nr1 = nextkomplex_nr1;
                komplex_nr2 = nextkomplex_nr2;
            }

            int color = j % 70;
            mandelbrot.setPix(i, z, color);
        }
    }

    mandelbrot.show();
    return 0;
}
#endif