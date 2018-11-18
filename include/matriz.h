#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include<math.h>
#include "utils.h"
using namespace std;

class matriz
{
    public:
        matriz();
        virtual ~matriz();

        void cria(int lin, int col);
        void leMatriz();
        void imprime();
        int getNlin();
        int getNcol();
        float getVal(int a, int b);

        void transpoe();
        void trocaLinha(matriz* mat, int tam, int lina,int linb);
        int escalona(matriz* mat);
        void multiplica(matriz* m2);

    private:
        float** mat;
        int* nlin;
        int* ncol;
};

#endif // MATRIZ_H
