#include "ponto.h"

ponto::ponto()
{
    //ctor
}

ponto::~ponto()
{
    //dtor
}
///==========================

void ponto::lePonto()
{
    cout << "Coordenada X: ";
    cin >> x;
    cout << "Coordenada Y: ";
    cin >> y;
    cout << "Coordenada Z: ";
    cin >> z;
}

float ponto::dist(ponto* p)
{
    return sqrt(pow((p->getX()-x),2)+pow((p->getY()-y),2)+pow((p->getZ()-z),2));
}

float ponto::getX(){return x;}
float ponto::getY(){return y;}
float ponto::getZ(){return z;}
