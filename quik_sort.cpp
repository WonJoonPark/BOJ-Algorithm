#include<iostream>
#include<vector>
using namespace std;

vector<int> InputToOutput;

void quicksort(int front, int rear) {
	if (front >= rear) { //하나이면 바로 return 
		return;
	}
	int pivot = front; //맨 첫번쨰 원소를 pivot으로 잡자
	int j = pivot + 1;
	int k = rear;
	int tmp;
	while (j<=k) {
		while (j <= rear && InputToOutput[j] <= InputToOutput[pivot]) {
			j++;
		}
		while (k > front  && InputToOutput[k] >= InputToOutput[pivot]) {
			k--;
		}
		if (j > k) { //엇갈린경우
			tmp = InputToOutput[k];
			InputToOutput[k] = InputToOutput[pivot];
			InputToOutput[pivot] = tmp;
		}
		else { // 아직 만나지 않았는데 멈춘경우 ---> j와k를 바꾸고 다시 진행
			tmp = InputToOutput[j];
			InputToOutput[j] = InputToOutput[k];
			InputToOutput[k] = tmp;
		}
	}
	quicksort( front, k - 1); //분할 정복.
	quicksort( k + 1, rear);
}
int main() {
	int tmpinput;
	while (cin >> tmpinput) {
		InputToOutput.push_back(tmpinput);
	}
	quicksort( 0, InputToOutput.size() - 1);
	for (int i = 0; i < InputToOutput.size(); i++) {
		cout << InputToOutput[i] << " ";
	}
	return 0;
}