#ifndef VETOR_H
#define VETOR_H
#include <iostream>
#include <math.h>
using namespace std;


class vetor
{
    public:
        vetor();
        virtual ~vetor();

        void leVetor();
        float norma();
        float produtoEscalar(vetor* v2);
        int getTam();

    private:
        float* vet;
        int t;
};

#endif // VETOR_H
