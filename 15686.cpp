#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int map[51][51];
vector<pair<int, int>> chikenstore; //��ü ġŲ���� ������ ��ǥ ����
vector<pair<int, int>> chosenstore; //���õ� ġŲ���� ������ ��ǥ ����(M��)
vector<pair<int, int>> home; //���� ��ġ�� ������ ��ǥ ���� (x,y) 
vector<int> result; //���

void InputMap() { //�Է¹޴� �Լ�
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				pair<int, int> tmp;
				tmp.first = i; tmp.second = j;
				chikenstore.push_back(tmp);
			}
			else if (map[i][j] == 1) {
				pair<int, int> tmp;
				tmp.first = i; tmp.second = j;
				home.push_back(tmp);
			}
		}
	}
}

int abs(int num1, int num2) { //���밪 ��ȯ
	if (num1 - num2 > 0) { return num1 - num2; }
	else { return num2 - num1; }
}

int loadsum(int x1, int y1, int x2, int y2) { //�Ÿ� ���
	return abs(x1, x2) + abs(y1, y2);
}

void caculatechickenload() { //������ ġŲ�Ÿ��� ���
	int sum = 0;
	for (int i = 0; i < home.size(); i++) { //������
		int min = 3000;
		for (int j = 0; j < chosenstore.size(); j++) { //ġŲ���� ���Ͽ� �Ÿ����(���� ����� ġŲ��=ġŲ�Ÿ�)
			if (min > loadsum(home[i].first, home[i].second, chosenstore[j].first, chosenstore[j].second)) {
				min = loadsum(home[i].first, home[i].second, chosenstore[j].first, chosenstore[j].second);
			}
		}
		sum += min;
	}
	result.push_back(sum);
}

void Mchickenstore(int index) {
	if (chosenstore.size() == M) { // M���� ����ٸ� ġŲ�Ÿ���� ����
		caculatechickenload();
		return;
	}
	for (int i = index; i < chikenstore.size(); i++) { //���� ����� ��
		chosenstore.push_back(chikenstore[i]);
		Mchickenstore(i + 1);
		chosenstore.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	InputMap();
	Mchickenstore(0);
	sort(result.begin(), result.end()); //���� �ּ� ����ġŲ�Ÿ� ���
	cout << result[0] << "\n";
	
	return 0;
}