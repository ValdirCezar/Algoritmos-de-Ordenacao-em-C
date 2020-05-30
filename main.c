#include <stdio.h>
#include <stdlib.h>

// Valdir Cezar 
// Engº de Software SENAI - Faculdades da Industria

typedef unsigned char bool;
bool false = 0, true = 1;
int count = 0;

int *readFile()
{
    char num;
    char buffer[10];
    int buffercount = 0;
    static int numbers[10000000];

    FILE *file = fopen("numeros.csv", "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(-1);
    }
    while (true)
    {
        if ((num = fgetc(file)) == EOF)
        {
            buffer[buffercount] = '\0';
            numbers[count] = atoi(buffer);
            count++;
            break;
        }
        if (num == ',')
        {
            buffer[buffercount] = '\0';
            numbers[count] = atoi(buffer);
            count++;
            buffercount = 0;
        }
        else if (buffercount < 10)
        {
            buffer[buffercount] = num;
            buffercount++;
        }
    }
    fclose(file);
    system("cls");
    printf("\nArquivo Carregado com sucesso!");
    return numbers;
}

void createFile(int *vet)
{
    FILE *arq = fopen("ORDENACAO.csv", "w"); //cria outro arquivo novamente
    if (arq == NULL)
    {
        printf("Erro ao criar o arquivo");
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(arq, "%i,", vet[i]);
    }
    fclose(arq);
    system("cls");
    printf("\nArquivo Criado com sucesso!");
}

void BubbleSort(int *vet[])
{
    int aux = 0;
    int i;
    for (i = 0; i < count; i++)
    {
        printf("Organizando %i de %i", i, count);
        system("cls");
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    if (i == count - 1)
    {
        printf("\nVetor Ordenado com sucesso!");
    }
}

void InsertionSort(int *vet)
{
    int i, j, numAtual = 0;

    for (i = 1; i < count; i++)
    {
        printf("Organizando %i de %i", i, count);
        system("cls");
        numAtual = vet[i];
        j = i - 1;

        while ((j >= 0) && (numAtual < vet[j]))
        {
            vet[j + 1] = vet[j];

            j--;
        }
        vet[j + 1] = numAtual;
    }
    if (i == count - 1)
    {
        printf("\nVetor Ordenado com sucesso!");
    }
}

void SelectionSort(int vet[])
{
    int i, j, aux = 0;

    for (i = 0; i < count; i++)
    {
        printf("Organizando %i de %i", i, count);
        system("cls");
        int menor = i;
        for (j = i + 1; j < count; j++)
        {
            if (vet[menor] > vet[j])
            {
                menor = j;
            }
            if (i != menor)
            {
                aux = vet[i];
                vet[i] = vet[menor];
                vet[menor] = aux;
            }
        }
    }
    if (i == count - 1)
    {
        printf("\nVetor Ordenado com sucesso!");
    }
}

int dividir(int vetor[],int esq, int dir){
    int aux; //troca de posicoes
    int cont = esq;

    for(int i=esq+1 ; i<=dir ; i++){

        if( vetor[i] < vetor[esq] ){
            cont++;
            aux=vetor[i];
            vetor[i]=vetor[cont];
            vetor[cont]=aux;
        }
    }

    aux=vetor[esq];
    vetor[esq]=vetor[cont];
    vetor[cont]=aux;

    return cont;
}

void quick(int vetor[],int esq, int dir){
    int pos;
    if(esq < dir){
        pos = dividir(vetor,esq,dir);
        quick(vetor,esq,pos-1);
        quick(vetor,pos+1,dir);
    }
}

void intercala(int p, int q, int r, int vet[]){
	int i, j, k, *w;

	w = malloc ((r-p) * sizeof(int));
	i = p;
	j = q;
	k = 0;

	while(i < q && j < r) {

		if(vet[i] <= vet[j])
			w[k++] = vet[i++];
		else
			w[k++] = vet[j++];

	}
	while(i < q){
		w[k++] = vet[i++];
	}
	while(j < r){
		w[k++] = vet[j++];
	}
	for(i = p; i < r; i++){
		vet[i] = w[i - p];
	}
	free(w);
}

void mergesort(int p, int r, int vet[]) {
	if(p < r - 1) {
		int q = (p + r)/2;
		mergesort(p, q, vet);
		mergesort(q, r, vet);
		intercala(p, q, r, vet);
	}
}

int main()
{
    int *vet;
    int op = 0;
    printf("\nCarregando arquivo...");
            vet = readFile();


    printf("\n---------------------- ALGORITMOS DE ORDENAÇÃO ------------------------");

    while (op != 7)
    {
        printf("\n Digite 1 para ordenar com Bubble Sort:\n Digite 2 para ordenar com Insertion Sort:\n Digite 3 para ordenar com Selection Sort:\n Digite 4 para ordenar com Quick Sort:\n Digite 5 para ordenar com Merge Sort:\n Digite 6 para sair:\n ");
        scanf("%i", &op);





        if (op == 1)
        {
            system("cls");
            printf("\nOrdenando o vetor com Bubble Sort... ");
            BubbleSort(vet);
            printf("\nCriando novo arquivo...!");
            createFile(vet); // depois que cada função de ordenação é chamada o programa grava um novo arquivo com o vetor ordenado
        }

        else if (op == 2)
        {
            system("cls");
            printf("\nOrdenando o vetor com Insertion Sort... ");
            InsertionSort(vet);
            printf("\nCriando novo arquivo...!");
            createFile(vet); // depois que cada função de ordenação é chamada o programa grava um novo arquivo com o vetor ordenado
        }
        else if (op == 3)
        {
            system("cls");
            printf("\nOrdenando o vetor com Selection Sort... ");
            SelectionSort(vet);
            printf("\nCriando novo arquivo...!");
            createFile(vet); // depois que cada função de ordenação é chamada o programa grava um novo arquivo com o vetor ordenado
        }
        else if (op == 4)
        {
            system("cls");
            printf("\nOrdenando o vetor com Quick Sort... ");
            quick(vet, 0, count);
            printf("\nCriando novo arquivo...!");
            createFile(vet); // depois que cada função de ordenação é chamada o programa grava um novo arquivo com o vetor ordenado
        }
        else if (op == 5)
        {
            system("cls");
            printf("\nOrdenando o vetor com Merge Sort... ");
            mergesort(0, count, vet);
            printf("\nCriando novo arquivo...!");
            createFile(vet); // depois que cada função de ordenação é chamada o programa grava um novo arquivo com o vetor ordenado
        }
        else
            exit(6);
    }
}
