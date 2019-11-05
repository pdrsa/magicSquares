#include <stdio.h>
#define N 100

int main()
{
    
    int n, num, i, j;

    scanf("%d", &n);

    int qMagico[n][n];

    //----------------------------Parte para N na forma 2n+1-----------------------------
    if (n % 2 == 1 )
    {
        //Zerando a matriz. Dessa forma onde tiver 0 é onde a matriz não foi alterada ainda
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                qMagico[i][j] = 0;
            }
        }

        //Essa é a posição que o número 1 irá ficar
        i = n/2; 
        j = n-1;

        //Laço para ir determinando a posição dos números
        for (num = 1; num <= n*n;)
        {
            //Tratamento para que posições maiores que n² funcionem.
            i = i % n;
            j = j % n;
            //Tratamento para que posições negativas funcionem.
            if (i < 0)
            {
                i = i + n;
            }

            if (j < 0)
            {
                j = j + n;
            }

            //Caso a posicao esteja vazia colocamos NUM na posição acima e a direita do antecessor.
            if (qMagico[i][j] == 0)
            {
                qMagico[i][j] = num;
                i--;
                j++;
                num++;
            }
            //Caso a posição esteja ocupada tentamos colocar NUM ao lado esquerdo de seu antecessor.
            else
            {
                j-=2;
                i++;
            }
        }
    }
    

    //----------------------------Parte para N na forma 4n-----------------------------
    else if (n % 4 == 0)
    {
        // Preenchemos o quadrado contando de 1 até n²
        for ( i = 0; i<n; i++)
        {
            for (j = 0; j<n; j++)
                qMagico[i][j] = (n*i) + j + 1;        
        }

        // Mudando os valores de acordo com a regra
        // (n*n+1)-qMagico[i][j]
        // Canto superior esquerdo do quadrado
        for ( i = 0; i<n/4; i++)
        {
            for ( j = 0; j<n/4; j++)
                qMagico[i][j] = (n*n + 1) - qMagico[i][j];
        }

        // Canto superior direito do quadrado
        for ( i = 0; i< n/4; i++)
        {
            for ( j = 3* (n/4); j<n; j++)
                qMagico[i][j] = (n*n + 1) - qMagico[i][j];
        }

        // Inferior esquerdo do quadrado
        for ( i = 3 * n/4; i<n; i++)
        {
            for ( j = 0; j<n/4; j++)
                qMagico[i][j] = (n*n + 1) - qMagico[i][j];
        }
    
        // Inferior direito do quadrado
        for ( i = 3 * n/4; i<n; i++)
        {
            for ( j = 3* n/4; j<n; j++)
                qMagico[i][j] = (n*n + 1) - qMagico[i][j];
        }
    
        // Agora invertemos as linhas da matriz 2x2 no centro do quadrado
        for ( i = n/4; i<3* n/4; i++)
        {
            for ( j = n/4; j<3* n/4; j++)
                qMagico[i][j] = (n*n + 1) - qMagico[i][j];
        } 
    }

    //----------------------------Parte para N na forma 4n + 2-----------------------------
    else if (n%4 == 2)
    {
        int qMagicoMini[n/2][n/2];

         //Zerando a matriz. Dessa forma onde tiver 0 é onde a matriz não foi alterada ainda
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                qMagicoMini[i][j] = 0;
            }
        }

        //Essa é a posição que o número 1 irá ficar
        i = n/4; 
        j = (n/2)-1;

        //Laço para ir determinando a posição dos números
        for (num = 1; num <= ((n/2))*((n/2));)
        {
            //Tratamento para que posições maiores que n² funcionem.
            i = i % (n/2);
            j = j % (n/2);
            //Tratamento para que posições negativas funcionem.
            if (i < 0)
            {
                i = i + (n/2);
            }

            if (j < 0)
            {
                j = j + (n/2);
            }

            //Caso a posicao esteja vazia colocamos NUM na posição acima e a direita do antecessor.
            if (qMagicoMini[i][j] == 0)
            {
                qMagicoMini[i][j] = num;
                i--;
                j++;
                num++;
            }
            //Caso a posição esteja ocupada tentamos colocar NUM ao lado esquerdo de seu antecessor.
            else
            {
                j-=2;
                i++;
            }
        }

        //Agora iremos fazer algumas alterações no mini quadrado

        //Primeiro vamos rodar ele 90º no sentido horário
        for (int x = 0; x < (n / 4); x++) 
        { 
            // Consider elements in group of 4 in  
            // current square 
            for (int y = x; y < (n/2)-x-1; y++) 
            { 
                // Guardando valor atual em variável temporária
                int aux = qMagicoMini[x][y]; 
    
                // Direita pra Cima
                qMagicoMini[x][y] = qMagicoMini[y][(n/2)-1-x]; 
    
                // Baixo pra Direita
                qMagicoMini[y][(n/2)-1-x] = qMagicoMini[(n/2)-1-x][(n/2)-1-y]; 
    
                // Esquerda pra Baixo
                qMagicoMini[(n/2)-1-x][(n/2)-1-y] = qMagicoMini[(n/2)-1-y][x]; 
    
                // Esquerda
                qMagicoMini[(n/2)-1-y][x] = aux;
            }
        }

        //Depois vamos espelhar ele no eixo vertical
        for (int i = 0; i < (n/2); i++)
        {
            for (int j = 0; j < (n/4); j++)
            {
                //Guardando na auxiliar
                int aux = qMagicoMini[i][j];
                //Trocando de posição pela coluna oposta
                qMagicoMini[i][j] = qMagicoMini[i][(n/2)-j-1];
                //Colocando a posição atual na coluna oposta
                qMagicoMini[i][(n/2)-j-1] = aux;
            }
        }

        //Agora preencheremos o Quadrado com variações de nosso Mini Quadrado
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < n/2 && j < n/2)
                    qMagico[i][j] = qMagicoMini[i][j];
                if (i >= n/2 && j < n/2)
                    qMagico[i][j] = qMagicoMini[i - (n/2)][j] + (3*n*n/4);
                if (i < n/2 && j >= n/2)
                    qMagico[i][j] = qMagicoMini[i][j - (n/2)] + (n*n/2);
                if (i >= n/2 && j >= n/2)
                    qMagico[i][j] = qMagicoMini[i - (n/2)][j - (n/2)] + (n*n/4);
            }
        }

        //Faremos umas trocas para que o quadrado se torne mágico, primeiramente trocando entre o quadrante 2 e 3 (Imagine os quadrantes do quadrado com os do plano cartesiano)
        //É extremamente recomendado o artigo Solving a Singly Even Magic Square do WikiHow para que se entenda a troca a seguir.
        int temp = n/4;
        
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/4; j++)
            {
                if (i == (temp) && j == 0)
                {
                    int aux = qMagico[i][j+(temp)];
                    qMagico[i][j+(temp)] = qMagico[i + (n/2)][j+(temp)];
                    qMagico[i + (n/2)][j+(temp)] = aux;
                }
                else
                {
                    int aux = qMagico[i][j];
                    qMagico[i][j] = qMagico[i+(n/2)][j];
                    qMagico[i+(n/2)][j] = aux;
                }
            }
        }

        //Caso o numero seja maior que 6 temos que fazer mais trocas
        if(n > 6)
        {
            for (int i = 0; i < n/2; i++)
            {
                for (int j = 0; j < temp-1; j++)
                {
                    int aux = qMagico[i][n-j-1];
                    qMagico[i][n-j-1] = qMagico[i+(n/2)][n-j-1];
                    qMagico[i + (n/2)][n-j-1] = aux;
                }
            }
        }

    }
    
    printf("\n\nn = %d, soma = %d\n\n", n, (((n*n) + 1)*(n/2)));
    FILE *fp = fopen("qMagico.txt", "w");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ", qMagico[i][j]);
            fprintf(fp, "%d  ", qMagico[i][j]);
        }
        fprintf(fp, "\n");
        printf("\n");
    }
    fclose(fp);

    return 0;

}