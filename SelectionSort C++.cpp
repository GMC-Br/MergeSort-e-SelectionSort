//A ordenacao por selecao e um algoritmo de ordenacao baseado em se passar sempre o menor valor do vetor para a primeira posicao
//depois o de segundo menor valor para a segunda posicao
//e assim e feito sucessivamente com os n-1 elementos restantes
//ate os ultimos dois elementos.

#include <bits/stdc++.h>
using namespace std;

// Funcao de troca
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// Um por um limite de movimento de
	// subarranjo nao classificado
	for (i = 0; i < n-1; i++)
	{
	
		// Encontre o elemento minimo em
		// matriz não classificada
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Troque o elemento minimo encontrado
		// com o primeiro elemento
		if(min_idx!=i)
			swap(&arr[min_idx], &arr[i]);
	}
}

//Funcao para imprimir um array
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "Matriz ordenada: \n";
	printArray(arr, n);
	return 0;
}
