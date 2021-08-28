#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX 30
#define N 10

// faturacao aleatorio
float Random()
{
    float num;
    num = rand() % 30001;
    return num;
}

typedef struct loja
{
    int numero;
    char nome[MAX];
    int area;
    float faturacao[12];
} Loja[N];

typedef struct ancora
{
    Loja loja1;
    float custoSeg;
} Ancora[N];

typedef struct restauracao
{
    Loja loja2;
    float custoSeg;
    float custoMan;
} Restauracao[N];

typedef struct centro
{
    char nome[MAX];
    char localidade[MAX];
    int qtdC;
    int qtdA;
    int qtdR;
    Loja vecComum[N];
    Ancora vecAncora[N];
    Restauracao vecRest[N];
} Centro;

void inserirCentro(Centro centro1)
{
    printf("Qual e o nome do centro comercial:");
    gets(centro1.nome);
    printf("Qual e a localidade do centro comercial:");
    gets(centro1.localidade);
}
/// estes 3  sao para o utilizador insirir as 3 primeiras lojas obrigatorias
void inserirComum(Loja vetC[])
{
    int i;
    printf("\nInsira uma loja comum");
    printf("\nNumero: ");
    scanf("%d", &(vetC[0]->numero));
    fflush(stdin);
    printf("Nome: ");
    gets(vetC[0]->nome);
    printf("Area: ");
    scanf("%d", &(vetC[0]->area));

    for (i = 0; i < 12; i++)
        vetC[0]->faturacao[i] = Random();
}

void inserirAncora(Ancora vetA[])
{
    int i;
    printf("\nInsira uma loja ancora");
    printf("\nNumero: ");
    scanf("%d", &(vetA[0]->loja1->numero));
    fflush(stdin);
    printf("Nome: ");
    gets(vetA[0]->loja1->nome);
    printf("Area: ");
    scanf("%d", &(vetA[0]->loja1->area));
    printf("Custo Seguranca: ");
    scanf("%f", &(vetA[0]->custoSeg));

    for (i = 0; i < 12; i++)
        vetA[0]->loja1->faturacao[i] = Random();
}

void inserirRestauracao(Restauracao vetR[])
{
    int i;
    printf("\nInsira uma loja de restauracao");
    printf("\nNumero: ");
    scanf("%d", &(vetR[0]->loja2->numero));
    fflush(stdin);
    printf("Nome: ");
    gets(vetR[0]->loja2->nome);
    printf("Area: ");
    scanf("%d", &(vetR[0]->loja2->area));
    printf("Custo Seguranca: ");
    scanf("%f", &(vetR[0]->custoSeg));
    printf("Custo Manutencao: ");
    scanf("%f", &(vetR[0]->custoMan));

    for (i = 0; i < 12; i++)
        vetR[0]->loja2->faturacao[i] = Random();
}

int ValorRenda()
{
    int renda;
    printf("\nInsira o valor da renda:");
    scanf("%d", &renda);
    while (renda <= 0)
    {
        printf("Insira um valor maior que zero.");
        scanf("%d", &renda);
    }
    return renda;
}

// Menu de op��es
char formulario()
{
    char r;
    do
    {
        system("cls");
        printf("------------------------------------\n\n");
        printf("1- Inserir lojas no centro comercial.\n");
        printf("2- Eliminar uma loja.\n");
        printf("3- Alterar o valor de faturacao para uma dada loja e para um dado mes.\n");
        printf("4- Mostrar todas as lojas pertencentes a uma dada classe.\n");
        printf("5- Listar todas as lojas do centro comercial .\n");
        printf("6- Mostrar o nome loja que mais faturou e a loja que menos faturou num dado mes.\n");
        printf("7- Mostrar o valor total anual das receitas do centro comercial.\n");
        printf("8- Mostrar o valor total anual da faturacao de uma loja.\n");
        printf("9- Mostrar uma listagem com os nomes das lojas e respetivos totais anuais de faturacao ordenada por ordem decrescente destes ultimos valores.\n");
        printf("s/S- Sair.\n");
        printf("------------------------------------\n\n");
        r = getch();
    } while (r != 's' && r != 'S' && r != '1' && r != '2' && r != '3' && r != '4' && r != '5' && r != '6' && r != '7' && r != '8' && r != '9');
    return r;
}

///esta serve para o utilizador escolher a loja que quer adicionar
char escolherloja_adicionar()
{
    char r;
    do
    {
        system("cls");
        printf("------------------------------------\n\n");
        printf("c- Inserir loja comum.\n");
        printf("a- Inserir loja ancora.\n");
        printf("r- Inserir loja de restauracao.\n");
        printf("s/S- Sair.\n");
        printf("------------------------------------\n\n");
        r = getch();
    } while (r != 's' && r != 'S' && r != 'c' && r != 'a' && r != 'r');
    return r;
}

char escolherloja_eliminar()
{
    int r;
    do
    {
        system("cls");
        printf("------------------------------------\n\n");
        printf("q- Eliminar loja comum.\n");
        printf("w- Eliminar loja ancora.\n");
        printf("e- Eliminar loja de restauracao.\n");
        printf("s/S- Sair.\n");
        printf("------------------------------------\n\n");
        r = getch();
    } while (r != 's' && r != 'S' && r != 'q' && r != 'w' && r != 'e');
    return r;
}

int AdicionarComum(int c, Loja vetC[])
{
    int i;
    for (i = c; i <= c; i++)
    {
        fflush(stdin);
        printf("\nInsira uma loja comum");
        printf("\nNumero: ");
        scanf("%d", &(vetC[c]->numero));
        fflush(stdin);
        printf("Nome: ");
        gets(vetC[c]->nome);
        fflush(stdin);
        printf("Area: ");
        scanf("%f", &(vetC[c]->area));
    }
    for (i = 0; i < 12; i++)
        vetC[c]->faturacao[i] = Random();
    c++;
    return c;
}

int AdicionarAncora(int a, Ancora vetA[])
{
    int i;
    for (i = a; i <= a; i++)
    {
        fflush(stdin);
        printf("\nInsira uma loja ancora");
        printf("\nNumero: ");
        scanf("%d", &(vetA[a]->loja1->numero));
        fflush(stdin);
        printf("Nome: ");
        gets(vetA[a]->loja1->nome);
        fflush(stdin);
        printf("Area: ");
        scanf("%f", &(vetA[a]->loja1->area));
        printf("Custo Seguranca: ");
        scanf("%f", &(vetA[a]->custoSeg));
    }
    for (i = 0; i < 12; i++)
        vetA[a]->loja1->faturacao[i] = Random();
    a++;
    return a;
}

int AdicionarRestauracao(int r, Restauracao vetR[])
{
    int i;
    for (i = r; i <= r; i++)
    {
        fflush(stdin);
        printf("\nInsira uma loja de restauracao");
        printf("\nNumero: ");
        scanf("%d", &(vetR[r]->loja2->numero));
        fflush(stdin);
        printf("Nome: ");
        gets(vetR[r]->loja2->nome);
        fflush(stdin);
        printf("Area: ");
        scanf("%f", &(vetR[r]->loja2->area));
        printf("Custo Seguranca: ");
        scanf("%f", &(vetR[r]->custoSeg));
        printf("Custo Manutencao: ");
        scanf("%f", &(vetR[r]->custoMan));
    }
    for (i = 0; i < 12; i++)
        vetR[r]->loja2->faturacao[i] = Random();
    r++;
    return r;
}

int MostrarComum(int c, Loja vetC[])
{
    int i, num;
    for (i = 0; i < c; i++)
    {
        printf("\nLoja %d, numero %d", i + 1, vetC[i]->numero);
    }
    printf("\nQual e a loja que quer eliminar:\n");
    scanf("%d", &num);
    return num;
}

int EliminarComum(int c, Loja vetC[])
{
    int posicao, i, a;

    posicao = MostrarComum(c, vetC);
    if (posicao > c || posicao < 1)
    {
        printf("Nao e possivel eliminar.\n");
        system("pause");
    }
    else
    {
        for (i = posicao - 1; i < c - 1; i++)
        {
            vetC[i]->numero = vetC[i + 1]->numero;
            strcpy((vetC[i]->nome), (vetC[i + 1]->nome));
            vetC[i]->area = vetC[i + 1]->area;
            for (a = 0; a < 12; a++)
                vetC[i]->faturacao[a] = vetC[i + 1]->faturacao[a];
        }
        c--;
    }
    return c;
}

int MostrarAncora(int a, Ancora vetA[])
{
    int i, num;
    for (i = 0; i < a; i++)
    {
        printf("\nLoja %d, numero %d", i + 1, vetA[i]->loja1->numero);
    }
    printf("\nQual e a loja que quer eliminar:\n");
    scanf("%d", &num);
    return num;
}

int EliminarAncora(int a, Ancora vetA[])
{
    int posicao, i, b;

    posicao = MostrarAncora(a, vetA);
    if (posicao > a || posicao < 1)
    {
        printf("Nao e possivel eliminar.\n");
        system("pause");
    }
    else
    {
        for (i = posicao - 1; i < a - 1; i++)
            vetA[i]->loja1->numero = vetA[i + 1]->loja1->numero;
        strcpy((vetA[i]->loja1->nome), (vetA[i + 1]->loja1->nome));
        vetA[i]->loja1->area = vetA[i + 1]->loja1->area;
        vetA[i]->custoSeg = vetA[i + 1]->custoSeg;
        for (b = 0; b < 12; b++)
            vetA[i]->loja1->faturacao[b] = vetA[i + 1]->loja1->faturacao[a];

        a--;
    }
    return a;
}

int MostrarRestauracao(int r, Restauracao vetR[])
{
    int i, num;
    for (i = 0; i < r; i++)
    {
        printf("\nLoja %d, numero %d", i + 1, vetR[i]->loja2->numero);
    }
    printf("\nQual e a loja que quer eliminar:\n");
    scanf("%d", &num);
    return num;
}

int EliminarRestauracao(int r, Restauracao vetR[])
{
    int posicao, i, a;

    posicao = MostrarRestauracao(r, vetR);
    if (posicao > r || posicao < 1)
    {
        printf("Nao e possivel eliminar.\n");
        system("pause");
    }
    else
    {
        for (i = posicao - 1; i < r - 1; i++)
            vetR[i]->loja2->numero = vetR[i + 1]->loja2->numero;
        strcpy((vetR[i]->loja2->nome), (vetR[i + 1]->loja2->nome));
        vetR[i]->loja2->area = vetR[i + 1]->loja2->area;
        vetR[i]->custoSeg = vetR[i + 1]->custoSeg;
        vetR[i]->custoMan = vetR[i + 1]->custoMan;
        for (a = 0; a < 12; a++)
            vetR[i]->loja2->faturacao[a] = vetR[i + 1]->loja2->faturacao[a];

        r--;
    }
    return r;
}

void MostrarTudoComum(int c, Loja vetC[])
{
    printf("----------Comum----------");
    int i, t;
    for (i = 0; i < c; i++)
    {
        printf("\nNumero: %d", vetC[i]->numero);
        printf("\nNome: %s", vetC[i]->nome);
        printf("\nArea: %d", vetC[i]->area);
        printf("\nFaturacao:[");
        for (t = 0; t < 12; t++)
            printf(" %.2f ", vetC[i]->faturacao[t]);
        printf("]");
        printf("\n---------------------------");
    }
}

void MostrarTudoAncora(int a, Ancora vetA[])
{
    printf("\n----------Ancora----------");
    int i, t;
    for (i = 0; i < a; i++)
    {
        printf("\nNumero: %d", vetA[i]->loja1->numero);
        printf("\nNome: %s", vetA[i]->loja1->nome);
        printf("\nArea: %d", vetA[i]->loja1->area);
        printf("\nCusto Seguranca: %.2f", vetA[i]->custoSeg);
        printf("\nFaturacao:[");
        for (t = 0; t < 12; t++)
            printf(" %.2f ", vetA[i]->loja1->faturacao[t]);
        printf("]");
        printf("\n---------------------------");
    }
}

void MostrarTudoRestauracao(int r, Restauracao vetR[])
{
    printf("\n----------Restauracao----------");
    int i, t;
    for (i = 0; i < r; i++)
    {
        printf("\nNumero: %d", vetR[i]->loja2->numero);
        printf("\nNome: %s", vetR[i]->loja2->nome);
        printf("\nArea: %d", vetR[i]->loja2->area);
        printf("\nCusto Seguranca: %.2f", vetR[i]->custoSeg);
        printf("\nCusto Seguranca: %.2f", vetR[i]->custoMan);
        printf("\nFaturacao:[");
        for (t = 0; t < 12; t++)
            printf(" %.2f ", vetR[i]->loja2->faturacao[t]);
        printf("]");
        printf("\n---------------------------");
    }
}

char EscolherFaturacao()
{
    int r;
    do
    {
        system("cls");
        printf("------------------------------------\n\n");
        printf("1- Mudar Faturacao loja comum.\n");
        printf("2- Mudar Faturacao loja ancora.\n");
        printf("3- Mudar Faturacao loja de restauracao.\n");
        printf("s/S- Sair.\n");
        printf("------------------------------------\n\n");
        r = getch();
    } while (r != 's' && r != 'S' && r != '1' && r != '2' && r != '3');
    return r;
}

int MostrarComumF(int c, Loja vetC[])
{
    int posicao, i;
    system("cls");
    for (i = 0; i < c; i++)
    {
        printf("\nLoja %d, numero %d", i + 1, vetC[i]->numero);
    }
    printf("\nQual e a loja que quer alterar faturacao:\n");
    scanf("%d", &posicao);
    return posicao;
}

void AlterarComumF(int posicao, int c, Loja vetC[])
{
    int mes;
    printf("Escolha o numero do mes que deseja alterar:");
    scanf("%d", &mes);
    if (mes > 12 || mes < 1)
    {
        printf("\nvalor nao valido.");
        printf("\nInsira um mes:");
        scanf("%d", &mes);
    }
    else
    {
        printf("Escolha o valor da faturacao <0,30000>\n");
        scanf("%f", &(vetC[posicao - 1]->faturacao[mes - 1]));
        if (vetC[posicao - 1]->faturacao[mes - 1] > 30000 || vetC[posicao - 1]->faturacao[mes - 1] < 0)
        {
            printf("Valor inv�lido,insira outro valor de faturacao:\n");
            scanf("%f", &(vetC[posicao - 1]->faturacao[mes - 1]));
        }
    }
}

int MostrarAncoraF(int a, Ancora vetA[])
{
    int posicao, i;
    system("cls");
    for (i = 0; i < a; i++)
    {
        printf("\nLoja %d, numero %d", i + 1, vetA[i]->loja1->numero);
    }
    printf("\nQual e a loja que quer alterar faturacao:\n");
    scanf("%d", &posicao);
    return posicao;
}

void AlterarAncoraF(int posicao, int a, Ancora vetA[])
{
    int mes;
    printf("Escolha o numero do mes que deseja alterar:");
    scanf("%d", &mes);
    if (mes > 12 || mes < 1)
    {
        printf("\nvalor nao valido.");
        printf("\nInsira um mes:");
        scanf("%d", &mes);
    }
    else
    {
        printf("Escolha o valor da faturacao <0,30000>\n");
        scanf("%f", &(vetA[posicao - 1]->loja1->faturacao[mes - 1]));
        if (vetA[posicao - 1]->loja1->faturacao[mes - 1] > 30000 || vetA[posicao - 1]->loja1->faturacao[mes - 1] < 0)
        {
            printf("Valor inv�lido,insira outro valor de faturacao:\n");
            scanf("%f", &(vetA[posicao - 1]->loja1->faturacao[mes - 1]));
        }
    }
}

int MostrarRestauracaoF(int r, Restauracao vetR[])
{
    int posicao, i;
    system("cls");
    for (i = 0; i < r; i++)
    {
        printf("\nLoja %d, numero %d", i + 1, vetR[i]->loja2->numero);
    }
    printf("\nQual e a loja que quer alterar faturacao:\n");
    scanf("%d", &posicao);
    return posicao;
}

void AlterarRestauracaoF(int posicao, int r, Restauracao vetR[])
{
    int mes;
    printf("Escolha o numero do mes que deseja alterar:");
    scanf("%d", &mes);
    if (mes > 12 || mes < 1)
    {
        printf("\nvalor nao valido.");
        printf("\nInsira um mes:");
        scanf("%d", &mes);
    }
    else
    {
        printf("Escolha o valor da faturacao <0,30000>\n");
        scanf("%f", &(vetR[posicao - 1]->loja2->faturacao[mes - 1]));
        if (vetR[posicao - 1]->loja2->faturacao[mes - 1] > 30000 || vetR[posicao - 1]->loja2->faturacao[mes - 1] < 0)
        {
            printf("Valor inv�lido,insira outro valor de faturacao:\n");
            scanf("%f", &(vetR[posicao - 1]->loja2->faturacao[mes - 1]));
        }
    }
}

void editarFaturacao(int c, int a, int r, Loja vetC[], Ancora vetA[], Restauracao vetR[])
{
    char editar;
    int posicao;
    do
    {
        editar = EscolherFaturacao();
        switch (editar)
        {
        case '1':
        {
            posicao = MostrarComumF(c, vetC);
            if (posicao > c || posicao < 1)
            {
                printf("Loja nao encontrada\n");
                system("pause");
            }
            else
                AlterarComumF(posicao, c, vetC);
            break;
        }
        case '2':
        {
            posicao = MostrarAncoraF(a, vetA);
            if (posicao > a || posicao < 1)
            {
                printf("Loja nao encontrada\n");
                system("pause");
            }
            else
                AlterarAncoraF(posicao, a, vetA);

            break;
        }
        case '3':
        {
            posicao = MostrarRestauracaoF(r, vetR);
            if (posicao > r || posicao < 1)
            {
                printf("Loja nao encontrada\n");
                system("pause");
            }
            else
                AlterarRestauracaoF(posicao, r, vetR);

            break;
        }
        }
    } while (editar != 's' && editar != 'S');
}

char mostrar_classes()
{
    int r;
    do
    {
        system("cls");
        printf("------------------------------------\n\n");
        printf("c- Mostrar lojas comum.\n");
        printf("a- Mostrar lojas ancora.\n");
        printf("r- Mostrar lojas de restauracao.\n");
        printf("s/S- Sair.\n");
        printf("------------------------------------\n\n");
        r = getch();
    } while (r != 's' && r != 'S' && r != 'c' && r != 'a' && r != 'r');
    return r;
}

void mostrar_comum(int c, Loja vetC[])
{
    int i;
    fflush(stdin);
    system("cls");
    printf("------------------------------------\n\n");
    for (i = 0; i < c; i++)
    {
        printf("\nLoja %d:", i + 1);
        printf("%s", vetC[i]->nome);
    }
    printf("\n------------------------------------\n\n");
    system("PAUSE");
}

void mostrar_ancora(int a, Ancora vetA[])
{
    int i;
    fflush(stdin);
    system("cls");
    printf("------------------------------------\n\n");
    for (i = 0; i < a; i++)
    {
        printf("\nLoja %d:", i + 1);
        printf("%s", vetA[i]->loja1->nome);
    }
    printf("\n------------------------------------\n\n");
    system("PAUSE");
}

void mostrar_restauracao(int r, Restauracao vetR[])
{
    int i;
    fflush(stdin);
    system("cls");
    printf("------------------------------------\n\n");
    for (i = 0; i < r; i++)
    {
        printf("\nLoja %d:", i + 1);
        printf("%s", vetR[i]->loja2->nome);
    }
    printf("\n------------------------------------\n\n");
    system("PAUSE");
}

int FaturacaoTotal(int c, int a, int r, Loja vetC[], Ancora vetA[], Restauracao vetR[], int renda_Base)
{
    int i, j, f_loja = 0, f_ancora = 0, f_restauracao = 0, F_C = 0, F_A = 0, F_R = 0, f_total1 = 0;

    for (i = 0; i < c; i++)
    {
        for (j = 0; j < 12; j++)
        {
            f_loja = f_loja + (vetC[i]->faturacao[j]) * 0.02 + renda_Base + (renda_Base * vetC[i]->area) / 100;
        }
        F_C = F_C + f_loja;
    }
    printf("%d", F_C);

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < 12; j++)
        {
            f_ancora = f_ancora + (vetA[i]->loja1->faturacao[j]) * 0.02;
        }
        F_A = F_A + renda_Base + f_ancora + (12 * (vetA[i]->custoSeg)) + (renda_Base * ((vetA[i]->loja1->area)) / 100);
    }
    printf("\n%d", F_A);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < 12; j++)
        {
            f_restauracao = f_restauracao + (vetR[i]->loja2->faturacao[j]) * 0.02;
        }
        F_R = F_R + renda_Base + f_restauracao + (12 * (vetR[i]->custoSeg)) + (12 * (vetR[i]->custoMan)) + (renda_Base * ((vetR[i]->loja2->area)) / 100);
    }

    printf("\n%d", F_R);

    f_total1 = F_C + F_A + F_R;
    printf("\n%d", f_total1);
    system("pause");
    return f_total1;
}

void MaiorMenor_C(int mes, int c, Loja vetC[], int MC[])
{
    int i, t;

    for (i = 0; i < c; i++)
    {
        if ((vetC[i]->faturacao[mes]) >= (vetC[i + 1]->faturacao[mes]))
        {
            MC[0] = i;
        }

        if ((vetC[i]->faturacao[mes]) <= (vetC[i + 1]->faturacao[mes]))
        {
            MC[1] = i;
        }
    }
}

void MaiorMenor_A(int mes, int a, Ancora vetA[], int MA[])
{
    int i, t;

    for (i = 0; i < a; i++)
    {
        if ((vetA[i]->loja1->faturacao[mes]) >= (vetA[i + 1]->loja1->faturacao[mes]))
        {
            MA[0] = i;
        }

        if ((vetA[i]->loja1->faturacao[mes]) <= (vetA[i + 1]->loja1->faturacao[mes]))
        {
            MA[1] = i;
        }
    }
}

void MaiorMenor_R(int mes, int r, Restauracao vetR[], int MR[])
{
    int i, t;

    for (i = 0; i < r; i++)
    {
        if ((vetR[i]->loja2->faturacao[mes]) >= (vetR[i + 1]->loja2->faturacao[mes]))
        {
            MR[0] = i;
        }

        if ((vetR[i]->loja2->faturacao[mes]) <= (vetR[i + 1]->loja2->faturacao[mes]))
        {
            MR[1] = i;
        }
    }
}

int MaiorF(int c, int a, int r, Loja vetC[], Ancora vetA[], Restauracao vetR[])
{
    int mes, MC[2], MA[2], MR[2];
    system("cls");
    //MC[0]=maior
    //MC[1]=menor
    printf("Escolha o mes:");
    scanf("%d", &mes);
    while (mes < 1 || mes > 12)
    {
        printf("Valor invalido, insira outro mes:");
        scanf("%d", &mes);
    }
    mes = mes - 1;
    MaiorMenor_C(mes, c, vetC, MC);

    MaiorMenor_A(mes, a, vetA, MA);

    MaiorMenor_R(mes, r, vetR, MR);

    if (vetC[MC[0]]->faturacao[mes] >= vetA[MA[0]]->loja1->faturacao[mes] && vetC[MC[0]]->faturacao[mes] >= vetR[MR[0]]->loja2->faturacao[mes])
    {
        printf("\nLoja que mais faturou foi: %s\n", vetC[MC[0]]->nome);
    }

    if (vetA[MA[0]]->loja1->faturacao[mes] >= vetC[MC[0]]->faturacao[mes] && vetA[MA[0]]->loja1->faturacao[mes] >= vetR[MR[0]]->loja2->faturacao[mes])
    {
        printf("\nLoja que mais faturou foi: %s\n", vetA[MA[0]]->loja1->nome);
    }

    if (vetR[MR[0]]->loja2->faturacao[mes] >= vetC[MC[0]]->faturacao[mes] && vetR[MR[0]]->loja2->faturacao[mes] >= vetA[MA[0]]->loja1->faturacao[mes])
    {
        printf("\nLoja que mais faturou foi: %s\n", vetR[MR[0]]->loja2->nome);
    }

    printf("\n--------------------------------------------------------\n");

    return mes;
}

void MenorF(int mes, int c, int a, int r, Loja vetC[], Ancora vetA[], Restauracao vetR[])
{
    int MC[2], MA[2], MR[2];

    MaiorMenor_C(mes, c, vetC, MC);

    MaiorMenor_A(mes, a, vetA, MA);

    MaiorMenor_R(mes, r, vetR, MR);

    if (vetA[MA[1]]->loja1->faturacao[mes] >= vetC[MC[1]]->faturacao[mes] && vetR[MR[1]]->loja2->faturacao[mes] >= vetC[MC[1]]->faturacao[mes])
    {
        // PrintComum(vetC,MC);
        printf("\nLoja que menos faturou foi: %s\n", vetC[MC[1]]->nome);
    }

    if (vetC[MC[1]]->faturacao[mes] >= vetA[MA[1]]->loja1->faturacao[mes] && vetR[MR[1]]->loja2->faturacao[mes] >= vetA[MA[1]]->loja1->faturacao[mes])
    {
        //PrintAncora(vetA,MA);
        printf("\nLoja que menos faturou foi: %s\n", vetA[MA[1]]->loja1->nome);
    }

    if (vetC[MC[1]]->faturacao[mes] >= vetR[MR[1]]->loja2->faturacao[mes] && vetA[MA[1]]->loja1->faturacao[mes] >= vetR[MR[1]]->loja2->faturacao[mes])
    {
        //PrintRestauracao(vetR,MR);
        printf("\nLoja que menos faturou foi: %s\n", vetR[MR[1]]->loja2->nome);
    }
}

void faturacao_comum(int c, Loja vetC[])
{
    printf("----------Comum----------");
    int i, t, f_anual = 0;
    for (i = 0; i < c; i++)
    {
        for (t = 0; t < 12; t++)
        {
            f_anual = f_anual + vetC[i]->faturacao[t];
        }
        printf("\n %s : %i euros", vetC[i]->nome, f_anual);
    }
}

void faturacao_ancora(int a, Ancora vetA[])
{
    printf("\n----------Ancora----------");
    int i, t, f_anual = 0;
    for (i = 0; i < a; i++)
    {
        for (t = 0; t < 12; t++)
        {
            f_anual = f_anual + vetA[i]->loja1->faturacao[t];
        }
        printf("\n %s : %i euros", vetA[i]->loja1->nome, f_anual);
    }
}

void faturacao_restauracao(int r, Restauracao vetR[])
{
    printf("\n----------Restauracao----------");
    int i, t, f_anual = 0;

    for (i = 0; i < r; i++)
    {
        for (t = 0; t < 12; t++)
        {
            f_anual = f_anual + vetR[i]->loja2->faturacao[t];
        }
        printf("\n %s : %i euros", vetR[i]->loja2->nome, f_anual);
    }
    printf("\n-------------------------------\n");
}

int AnualFaturacaoC(int c, Loja vetC[])
{
    int total = 0, i;
    for (i = 0; i < 12; i++)
    {
        total += vetC[c]->faturacao[i];
    }
    return total;
}

int AnualFaturacaoA(int a, Ancora vetA[])
{
    int total = 0, i;
    for (i = 0; i < 12; i++)
    {
        total += vetA[a]->loja1->faturacao[i];
    }
    return total;
}

int AnualFaturacaoR(int r, Restauracao vetR[])
{
    int total = 0, i;
    for (i = 0; i < 12; i++)
    {
        total += vetR[r]->loja2->faturacao[i];
    }
    return total;
}

int Case9(int c, int a, int r, Loja vetC[], Ancora vetA[], Restauracao vetR[])
{
    int i, N_total, ARRAYC[c], ARRAYA[a], ARRAYR[r], j;
    system("cls");
    N_total = c + a + r;
    int ARRAYT[N_total];
    for (i = 0; i < c; i++)
    {
        ARRAYC[i] = AnualFaturacaoC(i, vetC);
    }
    for (i = 0; i < a; i++)
    {
        ARRAYA[i] = AnualFaturacaoA(i, vetA);
    }
    for (i = 0; i < r; i++)
    {
        ARRAYR[i] = AnualFaturacaoR(i, vetR);
    }
    for (i = 0; i < c; i++)
    {
        ARRAYT[i] = ARRAYA[i];
    }
    for (i = c, j = 0; i < c + a; i++, j++)
    {
        ARRAYT[i] = ARRAYC[j];
    }
    for (i = c + a, j = 0; i < N_total; i++, j++)
    {
        ARRAYT[i] = ARRAYR[j];
    }
    for (i = 0; i < N_total; i++)
    {
        for (j = 0; j < N_total; j++)
        {
            if (ARRAYT[j] < ARRAYT[i])
            {
                int x = ARRAYT[i];
                ARRAYT[i] = ARRAYT[j];
                ARRAYT[j] = x;
            }
        }
    }
    printf("\n\nDecrescente : ");
    for (i = 0; i < N_total; i++)
    {
        printf(" %d ", ARRAYT[i]);
    }
    system("pause");
}

void main()
{
    int c = 1, a = 1, r = 1, f_total = 0, mes, renda_base;
    char ch, adicionar, eliminar, mostrarClasses;
    Centro centro1;
    Loja vetC[N];
    Ancora vetA[N];
    Restauracao vetR[N];
    srand(time(0));
    inserirCentro(centro1);
    inserirComum(vetC);
    inserirAncora(vetA);
    inserirRestauracao(vetR);
    renda_base = ValorRenda();
    do
    {
        ch = formulario();
        switch (ch)
        {

        case '1':
        {
            //Escolher loja quer inserir.
            do
            {
                adicionar = escolherloja_adicionar();

                switch (adicionar)
                {

                case 'c':
                {
                    if (c == N)
                    {
                        printf("Limite maximo de lojas atingido");
                        system("pause");
                    }
                    else
                        c = AdicionarComum(c, vetC);

                    break;
                }
                case 'a':
                {
                    if (a == N)
                    {
                        printf("Limite maximo de lojas atingido");
                        system("pause");
                    }
                    else
                        a = AdicionarAncora(a, vetA);

                    break;
                }
                case 'r':
                {
                    if (r == N)
                    {
                        printf("Limite maximo de lojas atingido");
                        system("pause");
                    }
                    else
                        r = AdicionarRestauracao(r, vetR);

                    break;
                }
                }
            } while (adicionar != 's' && adicionar != 'S');
            break;
        }
        case '2':
        {
            do
            {
                eliminar = escolherloja_eliminar();
                switch (eliminar)
                {
                case 'q':
                {
                    if (c < 2)
                    {
                        printf("Lojas insuficientes\n");
                        system("pause");
                    }
                    else
                        c = EliminarComum(c, vetC);

                    break;
                }
                case 'w':
                {
                    if (a < 2)
                    {
                        printf("Lojas insuficientes\n");
                        system("pause");
                    }

                    else
                        a = EliminarAncora(a, vetA);

                    break;
                }
                case 'e':
                {
                    if (r < 2)
                    {
                        printf("Lojas insuficientes\n");
                        system("pause");
                    }
                    else
                        r = EliminarRestauracao(r, vetR);

                    break;
                }
                }
            } while (eliminar != 's' && eliminar != 'S');
            break;
        }
        case '3':
        {
            //  editarFaturacao();
            editarFaturacao(c, a, r, vetC, vetA, vetR);

            break;
        }
        case '4':
        {
            do
            {
                mostrarClasses = mostrar_classes();
                switch (mostrarClasses)
                {
                case 'c':
                {
                    mostrar_comum(c, vetC);
                    break;
                }
                case 'a':
                {
                    mostrar_ancora(a, vetA);
                    break;
                }
                case 'r':
                {
                    mostrar_restauracao(r, vetR);
                    break;
                }
                }
            } while (mostrarClasses != 's' && mostrarClasses != 'S');
            break;
        }
        case '5':
        {
            system("cls");
            MostrarTudoComum(c, vetC);
            MostrarTudoAncora(a, vetA);
            MostrarTudoRestauracao(r, vetR);
            system("PAUSE");
            break;
        }
        case '6':
        {

            mes = MaiorF(c, a, r, vetC, vetA, vetR);

            MenorF(mes, c, a, r, vetC, vetA, vetR);
            system("pause");
            break;
        }
        case '7':
        {
            f_total = FaturacaoTotal(c, a, r, vetC, vetA, vetR, renda_base);
            system("cls");
            printf("------------------------------------\n\n");
            printf("O valor de faturacao total do centro = %d euros\n", f_total);
            printf("\n------------------------------------\n\n");
            system("PAUSE");
            break;
        }
        case '8':
        {
            system("cls");
            faturacao_comum(c, vetC);
            faturacao_ancora(a, vetA);
            faturacao_restauracao(r, vetR);
            system("PAUSE");
            break;
        }
        case '9':
        {
            Case9(c, a, r, vetC, vetA, vetR);
            break;
        }
        }
    } while (ch != 's' && ch != 'S');
    system("PAUSE");
}

