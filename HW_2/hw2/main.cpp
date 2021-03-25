#include <iostream>
#include <ctime>
#include <time.h>
#include <math.h>
#include <cmath>
#include <cstdlib>

using namespace std;


//used to create random arrays
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int N) {
	if (N <= 0) {
		arr1 = arr2 = arr3 = NULL;
		return;
	}
	arr1 = new int[N];
	arr2 = new int[N];
	arr3 = new int[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		arr1[i] = rand() % (2 * N);
		arr2[i] = arr3[i] = arr1[i];
	}
}

//*************************
 void swap(int& n1, int& n2) {

	int temp = n1;
	n1 = n2;
	n2 = temp;
}

 int partition(int input[], int p, int r) {

	int x = input[r], i = p - 1;
	for (int j = p; j < r; j++) {
		if (input[j] >= x) {
			i = i + 1;
			swap(input[i], input[j]);
		}
	}
	swap(input[i + 1], input[r]);
	return i + 1;
}

 void quickSort(int input[], int p, int r) {

	int q;
	if (p < r) {
		q = partition(input, p, r);
		quickSort(input, p, q - 1);
		quickSort(input, q + 1, r);
	}
}

//**3
 int findMin(int n1, int n2) {

	if (n1 <= n2)
		return n1;
	else
		return n2;
}

 int partition(int input[], int a, int p, int r) {

	int x = a, i = p - 1;
	for (int j = p; j < r; j++) {
		if (input[j] == x) {
			swap(input[j], input[r]);
		}
		if (input[j] >= x) {
			i = i + 1;
			swap(input[i], input[j]);
		}
	}
	swap(input[i + 1], input[r]);
	return i + 1;
}

 int select(int input[], int n, int k, int start, int end, int flag) {

	if (n <= 5) {
		quickSort(input, start, end);
		return input[start + k - 1];
	}
	int i = start, numGroups = (int)ceil((double)n / 5), numElements, j = 0;
	int* medians = new int[numGroups];
	while (i <= end) {
		numElements = findMin(5, end - i + 1);
		medians[(i - start) / 5] = select(input, numElements, (int)ceil((double)numElements / 2), i, i + numElements - 1, 1);
		i = i + 5;
	}
	int M = select(medians, numGroups, (int)ceil((double)numGroups / 2), 0, numGroups - 1, 1);
	delete[] medians;
	if (flag == 1)
		return M;
	int q = partition(input, M, start, end);
	int m = q - start + 1;
	if (k == m)
		return M;
	else if (k < m)
		return select(input, m - 1, k, start, q - 1, 0);
	else
		return select(input, end - q, k - m, q + 1, end, 0);
}

//**************************

void algo1(int input[], const int n, const int k, int output[]) {

	int maxIndex, maxValue;
	for (int i = 0; i < k; i++) {
		maxIndex = i;
		maxValue = input[i];
		for (int j = i + 1; j < n; j++) {
			if (input[j] >= maxValue) {
				maxIndex = j;
				maxValue = input[j];
			}
		}
		swap(input[i], input[maxIndex]);
		output[i] = input[i];
	}
}


void algo2(int input[], const int n, const int k, int output[]) {

	quickSort(input, 0, n - 1);
	for (int i = 0; i < k; i++) {
		output[i] = input[i];
	}
}

void algo3(int input[], const int n, const int k, int output[]) {

	select(input, n, k, 0, n - 1, 0);
	for (int i = 0; i < k; i++)
		output[i] = input[i];
}

//****************************

int main()
{
	int c = 0;
    std::cout << "Hello World!\n";
	int* arr1, * arr2, * arr3;
	double timeElapsed = 0;
	clock_t counter = 0;
	int size = 10000;
	for (; size <= 100000; size += 10000)
	{
		createRandomArrays(arr1, arr2, arr3, size);
		int* out1 = new int[size];
		int* out2 = new int[size];
		int* out3 = new int[size];
		cout << "*******" << endl;
		cout << "Size = " << size << endl;

		counter = clock();
		algo1(arr1, size, 1000, out1);
		counter = clock() - counter;
		timeElapsed = 1000 * double(counter) / CLOCKS_PER_SEC;
		cout << "Algoritm-1 Time: " << timeElapsed << endl;

		counter = clock();
		algo2(arr2, size, 1000, out2);
		counter = clock() - counter;
		timeElapsed = 1000 * double(counter) / CLOCKS_PER_SEC;
		cout << "Algoritm-2 Time: " << timeElapsed << endl;

		counter = clock();
		algo3(arr3, size, 1000, out3);
		counter = clock() - counter;
		timeElapsed = 1000 * double(counter) / CLOCKS_PER_SEC;
		cout << "Algoritm-3 Time: " << timeElapsed << endl;

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] out1;
		delete[] out2;
		delete[] out3;
		c++;
	}
	return 0;
	cout << c << endl;
}

