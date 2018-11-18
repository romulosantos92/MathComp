#include "matriz.h"

matriz::matriz()
{
    //ctor
    nlin=new int;
    ncol=new int;
}

matriz::~matriz()
{
    //dtor
    for(int i=0; i<*nlin; i++)
        delete []mat[i];
    delete []mat;
    delete nlin;
    delete ncol;
}
///============================

void matriz::cria(int lin, int col)
{
    mat=new float*[lin];
    for(int i=0; i<lin; i++)
        mat[i]=new float[col];
    *nlin=lin;
    *ncol=col;
}

int matriz::getNlin(){return *nlin;}
int matriz::getNcol(){return *ncol;}
float matriz::getVal(int a, int b){return mat[a][b];}

void matriz::trocaLinha(matriz* mat, int tam, int lina, int linb)
{
    float* auxlin=new float[tam];
    for(int i=0; i<tam;i++)
        auxlin[i]=mat->mat[lina][i];
    for(int i=0; i<tam;i++)
        mat->mat[lina][i]=mat->mat[linb][i];
    for(int i=0; i<tam;i++)
        mat->mat[linb][i]=auxlin[i];
}

int matriz::escalona(matriz* mat)
{
    int denominador=1;
    int comment=1;
    for(int i=0;i<*mat->nlin;i++)
    {
        if(mat->mat[i][i]==0)
        {
            if(comment)
                cout << "Case piv=0" << endl;
            int controle=0;
            for(int j=i+1;j<*mat->nlin;j++)
            {
                if(mat->mat[j][i]!=0)
                {
                    mat->trocaLinha(mat,*mat->ncol,i,j);
                    denominador*=-1;
                    controle++;
                    if(comment)
                    {
                        mat->imprime();
                        cout << endl << "Denominador: " << denominador << endl;
                    }
                }
            }
            if(controle==0)
                continue;
        }
        else if(mat->mat[i][i]<0)
        {
            for(int k=0;k<*mat->ncol;k++)
                if(mat->mat[i][k]!=0)
                    mat->mat[i][k]*=-1;
            denominador*=-1;
            if(comment)
            {
                cout << "Case piv<0" << endl;
                mat->imprime();
                cout << endl << "Denominador: " << denominador << endl;
            }
        }
        for(int j=i+1;j<*mat->nlin;j++)
        {
            if(comment)
                cout << endl << "operando linhas " << i << " e " << j << endl;
            if(mat->mat[j][i]<0)
            {
                for(int k=0;k<*mat->ncol;k++)
                {
                    if(mat->mat[j][k]!=0)
                        mat->mat[j][k]*=-1;
                }
                denominador*=-1;
                if(comment)
                {
                    cout << "Case -" << endl;
                    mat->imprime();
                    cout << endl << "Denominador: " << denominador << endl;
                }

                if(mat->mat[j][i]==mat->mat[i][i])
                {
                    for(int k=0;k<*mat->ncol;k++)
                        mat->mat[j][k]-=mat->mat[i][k];
                    if(comment)
                    {
                        cout << "Case ==" << endl;
                        mat->imprime();
                        cout << endl << "Denominador: " << denominador << endl;
                    }
                }
            }
            if((mat->mat[j][i]!=mat->mat[i][i])&&(mat->mat[j][i]!=0))///CASE PIV && OP !=MMC============
            {
                utils* m=new utils;
                if(comment)
                    cout << "Case !=" << endl;
                int mmc=m->mmc(mat->mat[j][i],mat->mat[i][i]);
                if(comment)
                    cout << "MMC " << mmc << endl;
                if((mat->mat[j][i]!=mmc)&&(mat->mat[i][i]!=mmc))
                {

                    int mp=mmc/mat->mat[j][i];
                    int mi=mmc/mat->mat[i][i];
                    for(int k=0;k<*mat->ncol;k++)
                    {
                        mat->mat[j][k]*=mp;
                        mat->mat[j][k]-=(mat->mat[i][k]*mi);
                    }
                    denominador*=mp;
                    if(comment)
                    {
                        cout << "case ii ji != mmc" << endl;
                        mat->imprime();
                        cout << endl << "Denominador: " << denominador << endl;
                    }
                    if(mat->mat[j][i]<0)
                    {
                        for(int k=0;k<*mat->ncol;k++)
                            if(mat->mat[j][k]!=0)
                                mat->mat[j][k]*=-1;
                        denominador*=-1;
                        if(comment)
                        {
                            cout << "Case -" << endl;
                            mat->imprime();
                            cout << endl << "Denominador: " << denominador << endl;
                        }
                    }
                }
                else if(mat->mat[j][i]!=mmc)///CASE OP!=MMC===============
                {
                    int m=mmc/mat->mat[j][i];
                    for(int k=0;k<*mat->ncol;k++)
                        mat->mat[j][k]*=m;
                    denominador*=m;
                    if(comment)
                    {
                        cout << "Case ji!=mmc" << endl;
                        mat->imprime();
                        cout << endl << "Denominador: " << denominador << endl;
                    }
                }
                else if(mat->mat[i][i]!=mmc)///CASE PIV!=MMC==============
                {
                    for(int k=0;k<*mat->ncol;k++)
                        mat->mat[j][k]-=(mat->mat[i][k]*(mmc/mat->mat[i][i]));
                    if(comment)
                    {
                        cout << "Case ii!=mmc" << endl;
                        mat->imprime();
                        cout << endl << "Denominador: " << denominador << endl;
                    }
                }
            }
            if(mat->mat[j][i]==mat->mat[i][i])///CASE EQUAL================
            {
                for(int k=0;k<*mat->ncol;k++)
                    mat->mat[j][k]-=mat->mat[i][k];
                if(comment)
                {
                    cout << "Case ==" << endl;
                    mat->imprime();
                    cout << endl << "Denominador: " << denominador << endl;
                }
            }
        }
    }
    return denominador;
}

void matriz::leMatriz()
{
    cout << endl << "Numero de linhas da matriz: ";
    cin >> *nlin;
    cout << "Numero de colunas da matriz: ";
    cin >> *ncol;
    cout << endl;
    mat=new float*[*nlin];
    for(int i=0; i<*nlin; i++)
        mat[i]=new float[*ncol];
    for(int i=0; i<*nlin; i++)
    {
        for(int j=0; j<*ncol; j++)
        {
            cout << "Elemento [" << i << ", " << j << "] da matriz: ";
            cin >> mat[i][j];
        }
    }
}

void matriz::imprime()
{
    cout << endl;
    for(int i=0; i<*nlin; i++)
    {
        for(int j=0; j<*ncol; j++)
        {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void matriz::transpoe()
{
    int* aux = new int;
    for(int i=0; i<*nlin; i++)
    {
        for(int j=0; j<*ncol; j++)
        {
            if((i!=j)&&(i<j))
            {
                *aux=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=*aux;
            }
        }
    }
    delete aux;
}

void matriz::multiplica(matriz* m2)
{
    float* aux=new float;
    matriz* m3=new matriz;
    m3->cria(*nlin, *m2->ncol);

    cout << "==============================" << endl << "MATRIZ A:" << endl;
    imprime();
    cout << "==============================" << endl << "MATRIZ B:" << endl;
    m2->imprime();

    for(int j=0; j<*m2->ncol;j++)
    {
        for(int i=0;i<*nlin;i++)
        {
            *aux=0;
            for(int k=0; k<*ncol;k++)
            {
                *aux+=mat[i][k]*m2->mat[k][j];
            }
            m3->mat[i][j]=(*aux);
        }
    }
    cout << endl << "==============================" << endl << "RESULTADO:" << endl;
    m3->imprime();
    cout << "==============================" << endl;
    delete aux;
}
