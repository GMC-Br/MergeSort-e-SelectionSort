#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// Um por um limite de movimento do subarranjo nao classificado
	for (i = 0; i < n-1; i++)
	{
		// Encontre o elemento minimo na matriz nao classificada
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Troque o elemento minimo encontrado pelo primeiro elemento
		if(min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}
}

/* Funcao para imprimir um array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Matriz ordenada: \n");
	printArray(arr, n);
	return 0;
}

