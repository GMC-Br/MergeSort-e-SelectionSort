//ele recebe como parametro o array a ser processados.
//Recebe tambem tres indices: left e mid e right, que determinam os limites em que o algoritmo deve agir
//A parte da divisao, na verdade, e bem simples. Basta “dividir” o array recursivamente na metade ate que sobre apenas um elemento.
//O que a gente faz e usar os indices left, mid e right para controlar as partes do array que o algoritmo deve agir.

#include <iostream>
using namespace std;

// Mescla dois subarrays de array[].
// O primeiro subarranjo e arr[begin..mid]
// O segundo subarranjo e arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Criar matrizes temporarias
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copiar dados para matriz temporarias leftArray[] e rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne
		= 0, // Indice inicial da primeira sub-matriz
		indexOfSubArrayTwo
		= 0; // Indice inicial da segunda submatriz
	int indexOfMergedArray
		= left; // Indice inicial da matriz mesclada

	// Mesclar as matrizes temporarias de volta na matriz[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copia os elementos restantes de
	// left[], se houver algum
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copia os elementos restantes de
	// right[], se houver algum
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin e para o Indice esquerdo e end e
// Indice direito da sub-matriz
// de arr a ser ordenado */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Retorna recursivamente

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// Funcao para imprimir um array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "A matriz dada e \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nA matriz ordenada e \n";
	printArray(arr, arr_size);
	return 0;
}
