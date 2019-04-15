#include <iostream>
#include "asciiimage.h"
/*
Authoren: Astrid Deleersnyder und Erisa Sala
*/

using namespace std;
//Char array mit die Zeichen
char zeichen[70] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m',
                    'Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t',
                    '/','\\','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l',
                    'I',';',':',',','"','^','`','\'','.',' '
                    };
// myAscii konstruktor
myAscii::myAscii(int width, int height)
{
    this->width = width;
    this->height = height;
    
    this->pic = new char*[width];
    for (int col = 0; col < width; col++)
    {
        this->pic[col] = new char[height];
        for (int row = 0; row < height; row++)
        {
            this->pic[col][row] = ' ';
        }
    }
}

myAscii::~myAscii()
{
    for (int col = 0; col < this->width; col++)
    {
        delete[] this->pic[col];
    }
    delete[] this->pic;
}
// Farbe Methode
void myAscii::setPix(int x, int y, int color)
{
    if (color >= 0 && color <= 69)
    {
        this->pic[x][y] = zeichen[69 - color];
    }
    else if (color < 0)
    {
        this->pic[x][y] = ' ';
    }
    else if (color > 69)
    {
        this->pic[x][y] = '$';
    }
}
//Printmethode
void myAscii::show()
{
    for (int row = 0; row < height; row++)
    {

        for (int col = 0; col < width; col++)
        {
            cout << this->pic[col][row];
        }
        cout << endl;
    }
}