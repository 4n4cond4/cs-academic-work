#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int l=0;
int c=0;
float dados;
int main()
{
    printf("############ Algoritmo de Decomposicao LU #####################\n");
    printf("Digite o numero de linhas da matriz:\n");
    scanf("%d", &l);
    printf("Digite o numero de colunas da matriz:\n");
    scanf("%d", &c);
    double Matriz[l][c];
    printf("A matriz tem %d linhas e %d colunas:\n",l,c);
    // definem vetores auxiliares para armazenar as trocas quais a linhas que foram trocadas e quais operações foram feitas para zerar
    double aux[c];
    int ordem[l];
    int ordem1[l];
    int auxOp;
    // int b = c-1;
    float op[l][c];
    for(int i=0; i < l; i++)
    {
        // Preenche a matriz
        for(int j=0; j < c; j++)
        {
            printf("Digite o valor da posicao:\n[%d][%d]=", i,j);
            scanf("%f",&dados);
            Matriz[i][j] = dados;
            //printf("%f \n", Matriz[i][j]);
        }
    }
    // mostra a matriz
    printf("\nA Matriz e: \n");
    for (int i=0; i < l; i++)
    {
        for (int j=0; j < c; j++)
        {
            if(j >= c-1)
            {
                printf("%.4f| \n", Matriz[i][j]);
            }
            else if(j==0)
            {
                printf("|%.4f ", Matriz[i][j]);
            }
            else
            {
                printf("%.4f ", Matriz[i][j]);
            }
        }
    }
    //carrega a ordem da matriz
    for (int i=0; i<l; i++)
    {
        ordem [i] = i;
    }
    //carrega a ordem da matriz
    for (int i=0; i<l; i++)
    {
        ordem1 [i] = i;
    }
    int b =0;
    float mod1;
    float mod2;
    // Organiza as linhas conforme o pivor do maior para o menor
    for(int i=0; i < 1; i++)  // anda linha
    {
        for(int j=i+1; j < l; j++)  // anda prox linha
        {
            if(fabs(Matriz[b][0]) < fabs(Matriz[j][0]))  //compara pivo linha com linha
            {
                for(int z=0; z < c; z++)  // anda coluna para fazer troca
                {
                    aux[z] = Matriz[j][z]; // adiciona linha menor no vetor
                }
                b=j;
                auxOp = ordem[i];
                ordem[i] = ordem[b];
                ordem[b] = auxOp;
                for(int z=0; z < c; z++)  // anda coluna para fazer troca
                {
                    Matriz[b][z]=Matriz[i][z]; // troca a linha da matriz menor pela proxima linha
                    Matriz[i][z]=aux[z]; // faz a proxima linha da matriz receber a linha menor
                }
            }
        }
    }
    // Mostra a matriz novamente
    printf("\n");
    printf("\nAplicando o pivoteamento na Matriz: \n");
    for (int i=0; i < l; i++)
    {
        for (int j=0; j < c; j++)
        {
            if(j >= c-1)
            {
                printf("%.4f| \n", Matriz[i][j]);
            }
            else if(j==0)
            {
                printf("|%.4f ", Matriz[i][j]);
            }
            else
            {
                printf("%.4f ", Matriz[i][j]);
            }
        }
    }
    for (int k=0; k < l; k++)
    {
        for (int y=0; y < c; y++)
        {
            op[k][y]= 0;
        }
    }
    for(int j=0; j < l; j++)
    {
        op[j][j]= 1;
    }
    double calc;
    double auxt[c];
    int v =0;
    // Aplica a eliminação de Gauss
    printf("\nAplicando a eliminacao de Gauss:");
    for(int i=0; i < l; i++)  // Define o numero de operações e anda o numero de linhas e colunas em det casos
    {
        for(int j=i+1; j < l; j++) // define qual linha vai ser operada
        {
            calc =Matriz[j][i]/Matriz[i][i];
            op[j][i] = calc;
            for (int y=i; y < c; y++)
            {
                Matriz[j][y] =(Matriz[j][y])- calc*Matriz[i][y];//opera as linhas definindo quais colunas vão ser zeradas
            }
        }
        v=i+1;
        // Organiza as linhas conforme o pivor do maior para o menor
        if(v < l-1)
        {
            // for(int f=0; f < 1; f++){ // anda linha
            for(int p=v+1; p < l; p++)  // anda prox linha
            {
                if(fabs(Matriz[v][i+1]) < fabs(Matriz[p][i+1]))  //compara pivo linha com linha
                {
                    for(int z=i+1; z < c; z++)  // anda coluna para fazer troca
                    {
                        auxt[z] = Matriz[p][z]; // adiciona o maior no vetor
                    }
                    v = p;
                    auxOp = ordem[i+1];
                    ordem[i+1] = ordem[v];
                    ordem[v] = auxOp;
                    for(int a=i+1; a < c; a++) // anda coluna para fazer troca
                    {
                        Matriz[v][a]=Matriz[i+1][a]; // troca a linha da matriz menor pela proxima linha
                        Matriz[i+1][a]=auxt[a]; // faz a proxima linha da matriz receber a linha menor

                    }
                }
            }
        }
    }
    printf("\n");
    // Mostra a matriz novamente
    printf("\nA matriz U e:\n");
    for (int i=0; i < l; i++)
    {
        for (int j=0; j < c; j++)
        {
            if(j >= c-1)
            {
                printf("%.4f| \n", Matriz[i][j]);
            }
            else if(j==0)
            {
                printf("|%.4f ", Matriz[i][j]);
            }
            else
            {
                printf("%.4f ", Matriz[i][j]);
            }
        }
    }
    printf("\n");
    //################ imprime matriz l de operações
    printf("\n Matriz L:\n");
    for (int i=0; i < l; i++)
    {
        for (int j=0; j < c; j++)
        {
            if(j >= c-1)
            {
                printf("%.4f| \n", op[i][j]);
            }
            else if(j==0)
            {
                printf("|%.4f ", op[i][j]);
            }
            else
            {
                printf("%.4f ", op[i][j]);
            }
        }
    }
    //Preenche o vetor B
    double vbc[l];
    float vlt=0;
    printf("\nDigite o vetor B:\n");
    for(int s =0; s < l; s++)
    {
        printf("B:[%d]= ",s);
        scanf("%e",&vlt);
        vbc[s] = vlt;

    }
    //permuta vetor b conforme a ultima troca da decomposição U
    int p;
    double u;
    double auxk[l];
    for(int i=0; i < l; i++)
    {
        p=ordem[i];
        for(int h=i; h<=i; h++)
        {
            u = vbc[p];
            auxk[h]= u;
        }
    }
    printf("\nAplicando Permutacao no vetor B:");
    printf("\n");
    for(int y=0; y < l; y++)
    {
        printf("\nB[%d] = %.3f",y,auxk[y]);
    }
    //Resolve o sistema LY=B
    double Vayb=0;
    double vaVet=0;
    int n=0;
    auxk[n]=(auxk[n]/op[n][n]);
    double soma1=0;
    for (int j=1; j < l; j++)
    {
        soma1=auxk[j];
        for (int i=0; i <= j-1; i++)
        {
            Vayb =(op[j][i]*auxk[i]);
            soma1=soma1-Vayb;
        }
        auxk[j]=(soma1/op[j][j]);
        soma1=0;
    }
    //resolve o sistema Ux=b
    double yt[l];
    for (int i =0; i<l; i++)
    {
        yt[i]=auxk[i];
    }
    printf("\n");
    double x[l];
    for (int g=0; g<l; g++)
    {
        x[g]=0;

    }
    int nt=0;
    nt=l-1;
    x[nt]=(yt[nt]/Matriz[nt][nt]);
    float soma=0;
    for(int k=nt-1; k >=0; k--)
    {
        soma=yt[k];
        for(int j=k+1; j <= nt; j++)
        {
            soma=soma - (Matriz[k][j]*x[j]);
        }
        x[k]=x[k]+(soma/Matriz[k][k]);
    }
    printf("\n\nO Resultado de Ly=B:");
    for(int z=0; z < l; z++)
    {
        printf("\n y[%d]= %.3f", z,auxk[z]);
    }
    printf("\n\nO Resultado de Ux=y:");
    for(int i=0; i<l; i++)
    {
        printf("\n x[%d]= %.3f",i,x[i]);
    }
    printf("\n");
    int operador=1;
    while(operador==1)
    {
        printf("\n Digite '1' para novo Vetor B ou '0' para sair: ");
        scanf("%d",&operador);
        if(operador==1)
        {
            //Preenche o vetor B
            double vbc[l];
            float vlt=0;
            printf("\nDigite o vetor B:\n");
            for(int s =0; s < l; s++)
            {
                printf("B:[%d]= ",s);
                scanf("%e",&vlt);
                vbc[s] = vlt;
            }
            //permuta vetor b conforme a ultima troca da decomposição U
            int p;
            double u;
            double auxk[l];
            for(int i=0; i < l; i++)
            {
                p=ordem[i];
                for(int h=i; h<=i; h++)
                {
                    u = vbc[p];

                    auxk[h]= u;
                }
            }
            printf("\nAplicando a eliminacao de Gauss No vetor B:");
            for (int j=0; j < l-1; j++)
            {
                for (int i=j+1; i < l; i++)
                {
                    auxk[i]=auxk[i]- (op[i][j]*auxk[j]);;
                }
            }
            printf("\n");
            for(int y=0; y < l; y++)
            {
                printf("\nB[%d] = %.3f",y,auxk[y]);
            }
            //Resolve o sistema LY=B
            double Vayb=0;
            double vaVet=0;
            int n=0;
            auxk[n]=(auxk[n]/op[n][n]);
            double soma1=0;
            for (int j=1; j < l; j++)
            {
                soma1=auxk[j];
                for (int i=0; i <= j-1; i++)
                {
                    Vayb =(op[j][i]*auxk[i]);
                    soma1=soma1-Vayb;
                }
                auxk[j]=(soma1/op[j][j]);
                soma1=0;
            }
            //resolve o sistema Ux=b
            double yt[l];
            for (int i =0; i<l; i++)
            {
                yt[i]=auxk[i];
            }
            printf("\n");
            double x[l];
            for (int g=0; g<l; g++)
            {
                x[g]=0;
            }
            int nt=0;
            nt=l-1;

            x[nt]=(yt[nt]/Matriz[nt][nt]);
            float soma=0;
            for(int k=nt-1; k >=0; k--)
            {
                soma=yt[k];
                for(int j=k+1; j <= nt; j++)
                {
                    soma=soma - (Matriz[k][j]*x[j]);
                }
                x[k]=x[k]+(soma/Matriz[k][k]);
            }
            printf("\n\n O Resultado de Ly=B:");
            for(int z=0; z < l; z++)
            {
                printf("\n y[%d]= %.3f", z,auxk[z]);
            }
            printf("\n\n O Resultado de Ux=Y:");
            for(int i=0; i<l; i++)
            {
                printf("\n x[%d]= %.3f",i,x[i]);
            }
            printf("\n");
        }
    }
    system("PAUSE");
    return 0;
}
