#include <iostream>
#include "mathcomp.h"
#include <stdlib.h>
#include "matriz.h"

///5 4 7 8 9 3 2 1 6

using namespace std;

int main()
{
    mathcomp m;
    int run=1;
    int op;

    while(run==1)
    {
        cout << endl;
        cout << "\t1-Distancia entre 2 pontos" << endl;
        cout << "\t2-Norma de um vetor" << endl;
        cout << "\t3-Produto escalar entre vetores" << endl;
        cout << "\t4-Verificar perpendicularidade entre vetores" << endl;
        cout << "\t5-MMC" << endl;
        cout << "\t6-Multiplicacao de matrizes" << endl;
        cout << "\t7-Determinante" << endl;
        cout << endl << endl << "\tselecione uma operacao: ";
        cin >> op;
        if((op>0)&&(op<8))
        {
            system("CLS");
            switch(op)
            {
                case 1:
                    m.distancia2Pontos();
                    break;
                case 2:
                    m.normaVetor();
                    break;
                case 3:
                    m.produtoEscalarVetores();
                    break;
                case 4:
                    m.ehPerpendicular();
                    break;
                case 5:
                    m.calcMMC();
                    break;
                case 6:
                    m.multiplicaMatrizes();
                    break;
                case 7:
                    m.determinante();
                    break;
            }
        }
        else
        {
            system("CLS");
            cout << endl << "Entrada invalida" << endl << "==============================" << endl;
        }
    }
    return 0;
}
