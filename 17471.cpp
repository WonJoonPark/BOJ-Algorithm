#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool check[11]; //�湮�� ������� Ȯ��
int groupindex[11]; //CASE�� �� ������ � ���ű��� ���ԵǾ��ִ��� Ȯ��
vector<int> edges[11]; //����� ���� ���� ����
int peoplecount[11]; //�� ������ �α��� ���庯��
int tmp;
int N;
vector<int> votecamp1; //���ű�1�� �ش��ϴ� ������ ���� ����
vector<int> resultmin;//�� CASE�� �α� �� ���̸� ��Ƴ��� ����

void input() {//�Է¹޴� �Լ�
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> peoplecount[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int n; cin >> n;
			edges[i].push_back(n);
		}
	}

}
int getsum(vector<int> arr) { //�α��� �� ���ϴ� �Լ�
	int s = 0;
	for (int i = 0; i < arr.size(); i++) {
		s += peoplecount[arr[i]];
	}
	return s;
}
void resetcheck() { //�ʱ�ȭ�Լ�
	for (int i = 0; i < 11; i++) {
		check[i] = false;
	}
}
int gap(int num1, int num2) { //�ܼ��� ���̸� �����ϴ� �Լ�
	if (num1 > num2) { return (num1 - num2); }
	else { return (num2 - num1); }
}
void dfs(int index,int g) { //DFS����
	check[index] = true;
	for (int i = 0; i < edges[index].size(); i++) {
		if (check[edges[index][i]]==false&&groupindex[edges[index][i]] == g) {
			//�湮���� �ʾҰ�, ���� ���� ���ű� �� ��� Ž���� ����
			dfs(edges[index][i],g);
		}
	}
	return;
}
bool all() { //��� �湮�ߴ��� üũ�� ���� �Լ�
	for (int i = 1; i <= N;i++) {
		if (check[i] == false) return false;
	}
	return true;
}
void groupindexreset() { //�ʱ�ȭ �Լ�
	for (int i = 0; i < 11; i++) {
		groupindex[i] = 1;
	}
}
void checkvotecamp() {
	if (votecamp1.size() == N) { return; }
	vector<int> votecamp2; //���ű�2�� ���� ����
	groupindexreset(); //�� ������ � ���ű��� ���ߴ����� ���� ���� �ʱ�ȭ
	for (int i = 1; i <= N; i++) { //1�� ������ ���� ������ 2�� �ֱ�
		bool c = false;
		for (int j = 0; j < votecamp1.size(); j++) {
			if (votecamp1[j] == i) { c = true; break; }
		}
		if (c == false) { votecamp2.push_back(i);
		groupindex[i] = 2;
		}
	}
	resetcheck();
	dfs(votecamp1[0],1); //���ű��� ������ ��� ����Ǿ��ִ��� üũ�� ���� DFS
	dfs(votecamp2[0],2);
	if (all() == true) {
		int first = getsum(votecamp1);
		int second = getsum(votecamp2);
		resultmin.push_back(gap(first, second));
	}

}
void makecase(int num) { //����CASE(���� �������� ����)
	if (num > N) { return; }
	for (int i = num; i <= N; i++) {
		votecamp1.push_back(i);
		checkvotecamp();
		makecase(i + 1);
		votecamp1.pop_back();
	}
}
int main() {
	// 1 ~ N �� ����
	input(); //�Է�
	makecase(1); //���̽� ������
	sort(resultmin.begin(), resultmin.end()); //�ּҰ� ��� ��
	if (resultmin.empty()) { cout << -1; return 0; }
	cout << resultmin[0];
	return 0;
}