#include<iostream>
using namespace std;

int sortedarray[20];
int Tosortarr[20];
void merge(int *arr, int start, int mid, int end) {
	int leftstart = start;
	int rightstart = mid + 1;
	int mergedindex = start;

	while (leftstart <= mid && rightstart <= end) {
		if (arr[leftstart] <= arr[rightstart]) {
			sortedarray[mergedindex] = arr[leftstart];
			leftstart++;
		}
		else {
			sortedarray[mergedindex] = arr[rightstart];
			rightstart++;
		}
		mergedindex++;
	}
	if (leftstart > mid) { //left 배열이 먼저 끝까지 온 경우 (비교연산을 통해)
		for (int i = rightstart; i <= end; i++) {
			sortedarray[mergedindex] = arr[i];
			mergedindex++;
		}
	}
	else {//right배열이 먼저 끝까지 온 경우
		for (int i = leftstart; i <= mid; i++) { 
			sortedarray[mergedindex] = arr[i];
			mergedindex++;
		}
	}
	for (int i = start; i <= end; i++) { //정렬이 끝난 배열 옮기기
		arr[i] = sortedarray[i];
	}
}

void mergeSort(int *arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main() {
	cout << "input : ";
	for (int i = 0; i < 20; i++) {
		cin >> Tosortarr[i];
	}
	cout << "\n";
	mergeSort(Tosortarr, 0, 19);
	cout << "output : ";
	for (int i = 0; i < 20; i++) {
		cout << Tosortarr[i] << " ";
	}
	return 0;
}