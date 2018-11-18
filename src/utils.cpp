#include "utils.h"

utils::utils()
{
    //ctor
}

utils::~utils()
{
    //dtor
}
int utils::mmc(int a, int b)
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
    for(int i=0; i<siz; i++)
    {
        if((va[i]>=vb[i])&&va[i]!=0)
            aux*=pow(p[i],va[i]);
        else if((va[i]<vb[i])&&vb[i]!=0)
            aux*=pow(p[i], vb[i]);
    }

    return (int)aux;
}
