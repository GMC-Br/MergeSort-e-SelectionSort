#include <stdio.h>
#include <stdlib.h>

// Mescla dois subarrays de arr[].
// O primeiro subarranjo e arr[l..m]
// O segundo subarranjo e arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* criar matrizes temporarias */
	int L[n1], R[n2];

	/* Copiar dados para matrizes temporarias L[] e R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Mescla as matrizes temporarias de volta em arr[l..r]*/
	i = 0; // Indice inicial do primeiro subarranjo
	j = 0; // Indice inicial do segundo subarranjo
	k = l; // Indice inicial do subarray mesclado
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copia os elementos restantes de L[], se houver algum */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copia os elementos restantes de R[], se houver algum */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l e para o índice esquerdo e r e o indice direito do
sub-matriz de arr a ser ordenada */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Igual a (l+r)/2, mas evita overflow para
// grandes l e h
		int m = l + (r - l) / 2;

		// Classificar primeiro e segundo tempo
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


/* Funcao para imprimir um array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("A matriz dada e \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nA matriz ordenada e \n");
	printArray(arr, arr_size);
	return 0;
}

