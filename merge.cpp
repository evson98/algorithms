/**
Merge Sort Algorithm C++ Example by Codebind.com
*/
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> num, int lo, int  mi, int hi) {
	//int temp [hi - lo + 1];

	/*int* temp = new int[hi - lo + 1];//temporary merger array
	int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
	int k = 0;//k is for the temporary array
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mi)
		temp[k++] = arr[i++];
	while (j <= hi)
		temp[k++] = arr[j++];
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];

	delete[]temp;*/

		int n1 = mi - lo + 1; // size of left vector
		int n2 = hi - mi; // size of right vector

		vector<int> L (n1);
		vector<int> R (n2);

		for (int i = 0; i < n1; i++) {
			L[i] = num[lo + i]; // initializing left part of numbers to L
		}

		for (int j = 0; j < n2; j++) {
			R[j] = num[mi + 1 + j]; // initializing right part of numbers to R
		}

		// L = 5 1
		// R = 8 0

		int i = 0; // init index of first subarray
		int j = 0; // init index of second subarray
			   
		int k = lo; // initial index of merged subarray

		/*while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				num[k++] = L[i++];
			}
			else {
				num[k++] = R[j++];
			}
			//k++;
		}*/

		for (k = lo; i < n1 && j < n2; k++)
		{
			if (L[i] < R[j])
			{
				num[k] = L[i++];
			}
			else
			{
				num[k] = R[j++];
			}
		}


		if (j == n2) {
			while (i < n1)
				num[k++] = L[i++];

		}
		else if (i == n1) {
			while (j < n2)
				num[k++] = R[j++];
		}

		for (int i = 0; i < num.size(); i++)
			cout << num[i] << " ";
		cout << endl;
	}

void MergeSort(vector<int> num, int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = (lo + hi) /2;
		MergeSort(num, lo, mid);
		MergeSort(num, mid + 1, hi);
		Merge(num, lo, mid, hi);
	}
}

int main() {
	vector<int> num { 5,1,8,0 };

	cout << "Before Merge Sort :" << endl;
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << " " << flush;
	cout << endl;

	MergeSort(num, 0, num.size() - 1);

	cout << "After Merge Sort :" << endl;
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << " " << flush;
	cout << endl;
	return (0);
}

