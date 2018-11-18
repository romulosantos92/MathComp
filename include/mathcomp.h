#ifndef MATHCOMP_H
#define MATHCOMP_H
#include <iostream>
#include "ponto.h"
#include "vetor.h"
#include "matriz.h"
#include <math.h>

using namespace std;


class mathcomp
{
    public:
        mathcomp();
        virtual ~mathcomp();

        void distancia2Pontos();

        void normaVetor();
        void produtoEscalarVetores();
        void ehPerpendicular();

        void multiplicaMatrizes();
        void determinante();

        void calcMMC();

        ///AUX====================
        int mmc(int a, int b);

    private:
};

#endif // MATHCOMP_H
