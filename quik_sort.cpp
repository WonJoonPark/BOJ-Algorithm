#include<iostream>
#include<vector>
using namespace std;

vector<int> InputToOutput;

void quicksort(int front, int rear) {
	if (front >= rear) { //�ϳ��̸� �ٷ� return 
		return;
	}
	int pivot = front; //�� ù���� ���Ҹ� pivot���� ����
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
		if (j > k) { //���������
			tmp = InputToOutput[k];
			InputToOutput[k] = InputToOutput[pivot];
			InputToOutput[pivot] = tmp;
		}
		else { // ���� ������ �ʾҴµ� ������ ---> j��k�� �ٲٰ� �ٽ� ����
			tmp = InputToOutput[j];
			InputToOutput[j] = InputToOutput[k];
			InputToOutput[k] = tmp;
		}
	}
	quicksort( front, k - 1); //���� ����.
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