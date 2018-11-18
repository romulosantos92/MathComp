#include "vetor.h"

vetor::vetor()
{
    //ctor
}

vetor::~vetor()
{
    //dtor
    delete [] vet;
}
///========================================
int vetor::getTam()
{
    return t;
}
///========================================
void vetor::leVetor()
{
    cout << "Qual a dimensao do vetor? ";
            cin >> t;
            cout << endl;
            vet=new float [t];
            for(int i=0; i<t; i++)
            {
                cout << "Coordenada " << i << ": ";
                cin >> vet[i];
            }
}

float vetor::norma()
{
    float sqr=0;
            for(int i=0; i<t; i++)
                sqr+=pow(vet[i], 2);
            return sqrt(sqr);
}

float vetor::produtoEscalar(vetor* v2)
{
    float sqr=0;
            for(int i=0; i<t; i++)
                sqr+=pow(vet[i]*v2->vet[i], 2);
            return sqrt(sqr);
}
