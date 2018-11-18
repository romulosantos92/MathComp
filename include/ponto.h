#ifndef PONTO_H
#define PONTO_H
#include <iostream>
#include <math.h>
using namespace std;


class ponto
{
    public:
        ponto();
        virtual ~ponto();

        void lePonto();
        float dist(ponto* p);

        float getX();
        float getY();
        float getZ();

    private:

        float x;
        float y;
        float z;
};

#endif // PONTO_H
