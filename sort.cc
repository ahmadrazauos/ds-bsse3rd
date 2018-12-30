#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void selectionSort(int a[], int size) {
	for(int i=0; i < size -1; i++) {
		int minimumIndex = i;
		for(int j=i; j < size; j++) {
			if(a[j] < a[minimumIndex]) {
				minimumIndex = j;
			}
		}
		if(minimumIndex != i) {
			swap(a[minimumIndex], a[i]);
		}
	}
}

void insertionSort(int a[], int size) {
	for(int i=1; i < size; i++) {
		for(int j=i; j > 0; j--) {
			if(a[j] < a[j-1]) {
				swap(a[j], a[j-1]);
			}
		}
	}
}

/* MERGE SORT */
void merge(int a[], int low, int mid, int high) {
	int i, j, k, n1, n2;
	n1 = mid - low + 1;
	n2 = high - mid;
	int aleft[n1], aright[n2];
	
	for(i=0; i < n1; i++)
		aleft[i] = a[low + i];
	for(j=0; j < n1; j++)
		aright[j] = a[mid + 1 + j];
	i = j = 0;
	k = low;
	while(i < n1 && j < n2) {
		if(aleft[i] <= aright[j]) 
			a[k++] = aleft[i++];
		else
			a[k++] = aright[j++];
	}
	while(i < n1) {
		a[k++] = aleft[i++];
	}
	while(j < n2) {
		a[k++] = aright[j++];
	}
}

void mergeSort(int a[], int low, int high) {
	if(low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Quick Sort */
int partition(int a[], int low, int high) {
	int pivot = a[low], pivotIndex = low, i, j;
	i = j = low;

	while(i <= high) {
		if(a[i] <= pivot) {
			if(i != j)
				swap(a[i], a[++j]);
		}
		i++;
	}
	swap(a[j], a[pivotIndex]);
	return j;
}

int quickSort(int a[], int low, int high) {
	if(low < high) {
		int pi = partition(a, low, high);
		quickSort(a, low, pi-1);
		quickSort(a, pi + 1, high);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void print(int a[], int size) {
	for(int i=0; i<size; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main(int argc, char **argv) {
	int a[8] = {5,10,11,7,6,18,43,3};
	selectionSort(a, 8);
	print(a, 8);
	
	int b[8] = {5,10,11,7,6,18,43,3};
	insertionSort(b, 8);
	print(b, 8);
	
	int c[8] = {5,10,11,7,6,18,43,3};
	mergeSort(c, 0, 7);
	print(c, 8);


	int d[8] = {5,10,11,7,6,18,43,3};
	quickSort(d, 0, 7);
	print(d, 8);

	return 0;
}
