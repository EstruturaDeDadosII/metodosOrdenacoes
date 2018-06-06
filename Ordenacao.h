//
// Created by thiago on 5/30/2018.
//

#ifndef ORDENACAO_ORDENACAO_H
#define ORDENACAO_ORDENACAO_H


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



class Ordenacao {

    public:
    void bubble_sort(int vetor[], int n) {
        int k, j, aux;
        for (k = 1; k < n; k++) {
            for (j = 0; j < n - 1; j++) {
                if (vetor[j] > vetor[j + 1]) {
                    aux          = vetor[j];
                    vetor[j]     = vetor[j + 1];
                    vetor[j + 1] = aux;
                }
            }
        }
    }

    void insertionSort(int arr[], int n)
    {
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i-1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
        }
    }

    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high- 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }


    int shellSort(int arr[], int n)
    {
        for (int gap = n/2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i += 1)
            {
                int temp = arr[i];

                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                arr[j] = temp;
            }
        }
        return 0;
    }


    void merge(int arr[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;


        int L[n1], R[n2];


        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];


        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }


        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }


        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }


    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {

            int m = l+(r-l)/2;


            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }



    void bucketSort(float arr[], int n)
    {

        vector<float> b[n];


        for (int i=0; i<n; i++)
        {
            int bi = n*arr[i];
            b[bi].push_back(arr[i]);
        }

        for (int i=0; i<n; i++)
            sort(b[i].begin(), b[i].end());

        int index = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b[i].size(); j++)
                arr[index++] = b[i][j];
    }


    void imprimir(int vetor[], int tamanho){
        for(int i = 0; i<tamanho;i++){
            printf("%d ", vetor[i]);
        }
    }



    void imprimir_f(float vetor[], int tamanho) {
        for (int i = 0; i < tamanho; i++) {
            printf("%f ", vetor[i]);
        }
    }

};








#endif //ORDENACAO_ORDENACAO_H
