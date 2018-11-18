#include "mathcomp.h"


mathcomp::mathcomp()
{
    //ctor
    cout << endl << endl << "\tMATHCOMP BETA v1.0" << endl << "\tRomulo Santos" << endl << endl <<
    "\tEste programa foi criado no intuito de auxiliar estudantes," << endl <<
    "\tpara que possam conferir os resultados de seus exercicios." << endl <<
    "\tQuaisquer Bugs ou duvidas, enviar para:" << endl <<
    "\tromulosantos1092@gmail.com" << endl << endl << "==============================" << endl;
}

mathcomp::~mathcomp()
{
    //dtor
}
void mathcomp::distancia2Pontos()
{
    ponto* p1=new ponto;
    ponto* p2=new ponto;
    cout << endl << "DISTANCIA ENTRE 2 PONTOS" << endl;
    cout << endl << "Ponto 1:" << endl;
    p1->lePonto();
    cout << endl << "Ponto 2:" << endl;
    p2->lePonto();
    cout << endl << "A distancia entre os pontos eh: " << p1->dist(p2) << endl << endl << "==============================" << endl;
    delete p1;
    delete p2;
}

void mathcomp::normaVetor()
{
    vetor* v=new vetor;
    cout << endl << "NORMA DE UM VETOR" << endl << endl;
    v->leVetor();
    cout << endl << "A norma do vetor eh: " << v->norma() << endl << endl << "==============================" << endl;
    delete v;
}

void mathcomp::produtoEscalarVetores()
{
    vetor* v1=new vetor;
    vetor* v2=new vetor;
    cout << "PRODUTO ESCALAR VETORIAL" << endl << endl;
    cout << "Vetor 1:" << endl;
    v1->leVetor();
    cout << endl << "Vetor 2:" << endl;
    v2->leVetor();
    if(v1->getTam()==v2->getTam())
        cout << endl << "O produto escalar eh: " << v1->produtoEscalar(v2) << endl << endl << "==============================" << endl;
    else
        cout << endl << "Impossivel operar: Dimensoes diferentes." << endl << endl << "==============================" << endl;
    delete v1;
    delete v2;
}

void mathcomp::ehPerpendicular()
{
    vetor* v1=new vetor;
    vetor* v2=new vetor;
    double* p=new double;
    cout << "TESTE - PERPENDICULARIDADE" << endl << endl;
    cout << "Vetor 1:" << endl;
    v1->leVetor();
    cout << endl << "Vetor 2:" << endl;
    v2->leVetor();
    if(v1->getTam()==v2->getTam())
    {
        *p=v1->produtoEscalar(v2);
        if(*p==0)
            cout << endl << "Os vetores sao perpendiculares entre si" << endl << endl << "==============================" << endl;
        else
            cout << endl << "Os vetores nao sao perpendiculares" <<  endl << endl << "==============================" << endl;
    }
    else
        cout << endl << "Impossivel operar: Dimensoes diferentes." << endl << endl << "==============================" << endl;
    delete p;
    delete v1;
    delete v2;
}

int mathcomp::mmc(int a, int b)
{
    int siz=168;
    int range=1000;
    int* p=new int[siz]; ///Vetor de primos
    int* va=new int[siz];///Vetor de expoentes de a
    int* vb=new int[siz];///Vetor de expoentes de b
    int c=0;
    for(int i=2; i<range; i++)///Preenche vetor p com primos
    {
        int t=0;
        for(int j=1; j<=i;j++)
        {
            if(i%j==0)
            {
                t++;
            }
        }
        if(t==2)
        {
            p[c]=i;
            c++;
        }
    }
    for(int i=0; i<siz; i++)///preenche va e vb com 0
    {
        va[i]=0;
        vb[i]=0;
    }
    double aux=1;///Inicializa aux

    if(a<0)   ///Elimina negativos nas entradas
        a*=-1;
    if(b<0)
        b*=-1;

    for(int i=0; i<siz, a>1;)
    {
        if(a%p[i]==0)
        {
            va[i]+=1;
            a/=p[i];
        }
        else
            i++;
    }
    for(int i=0; i<siz, b>1;)
    {
        if(b%p[i]==0)
        {
            vb[i]+=1;
            b/=p[i];
        }
        else
            i++;
    }

    cout << endl << "A:";
    for(int i=0; i<siz; i++)
        if(va[i]!=0)
            cout << p[i] << "^" << va[i] << "   ";
    cout << endl ;
    cout << endl << "B:";
    for(int i=0; i<siz; i++)
        if(vb[i]!=0)
            cout << p[i] << "^" << vb[i] << "   ";
    cout << endl;

    for(int i=0;i<siz; i++)
    {
        if((va[i]>=vb[i])&&va[i]!=0)
            aux*=pow(p[i],va[i]);
        else if((va[i]<vb[i])&&vb[i]!=0)
            aux*=pow(p[i], vb[i]);
    }
    return (int)aux;
}

void mathcomp::calcMMC()
{
    double* a=new double;
    double* b=new double;
    cout << "MINIMO MULTIPLO COMUM" << endl << endl;
    cout << "Valor 1: ";
    cin >> *a;
    cout << "Valor 2: ";
    cin >> *b;
    cout << endl << "O mmc entre " << *a << " e " << *b << " eh: " << mmc(*a, *b) << endl << endl << "==============================" << endl;;
    delete a;
    delete b;
}

void mathcomp::multiplicaMatrizes()
{
    matriz* m1=new matriz;
    matriz* m2=new matriz;
    cout << "MULTIPLICACAO DE MATRIZES" << endl << endl;
    cout << endl << "MATRIZ A:";
    m1->leMatriz();
    cout << endl << "MATRIZ B:";
    m2->leMatriz();
    if(m1->getNcol()==m2->getNlin())
        m1->multiplica(m2);
    else
        cout << endl << "Erro-Impossivel operar: A quantidade de colunas de A \
        nao eh igual a quantidade de linhas de B" << endl << endl << "==============================" << endl;
}

void mathcomp::determinante()
{
    matriz* a=new matriz;
    a->leMatriz();
    a->imprime();
    if(a->getNlin()!=a->getNcol())
        cout << endl << "ERRO-Matriz nao quadrada" << endl << endl << "==============================" << endl;
    else
    {
        int d=a->escalona(a);
    int n=1;
    for(int i=0;i<a->getNcol();i++)
        n*=a->getVal(i,i);
    cout << endl << "O determinante da matriz eh: " << n/d << endl << endl << "==============================" << endl;
    }
    delete a;
}
