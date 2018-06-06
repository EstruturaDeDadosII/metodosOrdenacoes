#include <iostream>
#include <stdlib.h>
#include "Ordenacao.h"
#include <deque>
#include <ctime>


int teste = 0, *vetor;

deque<int> _vetor;

float vetorFlutuante[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

Ordenacao ordenacao;

void menu();


int getNumeroAleatorio() {
    int min = 0;
    int max = INT8_MAX;
    return min + rand() * (max - min) / RAND_MAX;;
}

void cadastrar(){

    int quantidade;
    cout << endl << "Quantidade de numeros que deseja cadastrar: " << endl;
    cin >> quantidade;

    for (int i = 0; i < quantidade; ++i) {
        if(teste == 0){
            teste++;
            vetor = (int *) malloc (teste*sizeof(int));
            vetor[teste-1] = getNumeroAleatorio();
        }else{
            teste++;
            vetor = (int *)realloc(vetor, teste*sizeof(int));
            vetor[teste-1] = getNumeroAleatorio();
        }
    }

}

float calculaTempoGasto(clock_t t0, clock_t tf) {
    return ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
}


int main() {

    menu();
    return 0;
}


void menu () {

    int escolha, num;
    clock_t t0, tf;
    double tempo_gasto;

    cout << "[1] Inserir elemento" << endl;
    cout << "[2] Imprimir elemento" << endl;
    cout << "[3] Burble sort" << endl;
    cout << "[4] Insert Sort" << endl;
    cout << "[5] Quick sort" << endl;
    cout << "[6] Shell sort" << endl;
    cout << "[7] Merge Sort" << endl;
    cout << "[8] Bucket Sort" << endl;
    cout << "[0] SAIR" << endl;
    cout << "Escolha uma opcao valida: ";
    cin >> escolha;

    system("cls");
    switch(escolha){
        case 0:
            return;

        case 1:
            t0 = clock();
            cout<<"Os numeros serao adicionados pela maquia ";
            cadastrar();
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao para cadastrar: " << tempo_gasto << endl << endl;
            break;

        case 2:
            t0 = clock();
            ordenacao.imprimir(vetor, teste);
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao para imprimir: " << tempo_gasto << endl << endl;

            break;

        case 3:
            t0 = clock();
            ordenacao.bubble_sort(vetor, teste);
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao Burble sort: " << tempo_gasto << endl << endl;
            break;

        case 4:
            t0 = clock();
            ordenacao.insertionSort(vetor, teste);
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao para Insetion Sort: " << tempo_gasto << endl << endl;
            break;

        case 5:
            t0 = clock();
            ordenacao.quickSort(vetor, 0, teste-1);
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao para Quick sort: " << tempo_gasto << endl << endl;
            break;

        case 6:
            t0 = clock();
            ordenacao.shellSort(vetor, teste);
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao para Shell Sort: " << tempo_gasto << endl << endl;
            break;

        case 7:
            t0 = clock();
            ordenacao.mergeSort(vetor,0, teste-1);
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao para Merge Sort: " << tempo_gasto << endl << endl;
            break;

        case 8:
            t0 = clock();
            ordenacao.bucketSort(vetorFlutuante, 6);
            ordenacao.imprimir_f(vetorFlutuante, 6);
            tf = clock();
            tempo_gasto = calculaTempoGasto(t0, tf);
            cout << "Tempo de execucao para Bucket Sort: " << tempo_gasto << endl << endl;

            break;
    }

    menu();

}

