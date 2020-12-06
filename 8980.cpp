#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct box {
	int start;
	int end;
	int weight;
};
int N,C; //������ �� , Ʈ���� �뷮
int M; // �ڽ������� ��
int x, y, weight;
int result;
int truck[2001]; //���� �� Ʈ���� ������ ǥ���ϱ� ���ؼ� (Ʈ���� �ö��ִ� �ڽ��� ����)

bool compare(box &lhs, box &rhs) {
	if (lhs.end < rhs.end) return true;
	else if (lhs.end == rhs.end) {
		if (lhs.start <= rhs.start) return true;
		else return false;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C; //���� �� �� Ʈ���� �뷮
	cin >> M;
	vector<box> sendbox(M);
	for (int i = 0; i < M; i++) {
		cin >> sendbox[i].start >> sendbox[i].end>>sendbox[i].weight;
	}
	sort(sendbox.begin(), sendbox.end(), compare);

	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = sendbox[i].start; j < sendbox[i].end; j++) {
			cnt = max(truck[j], cnt);
		}
		result += min(sendbox[i].weight, C - cnt); //�ڽ��� �ø��� (���� �� �ִ� ���� �� ������ �� ��ŭ�� �ø� �� �ִ�)
		for (int j = sendbox[i].start; j < sendbox[i].end; j++) { //�� ��ŭ �������� ���������� Ʈ���� �뷮���� ����
			truck[j] += min(sendbox[i].weight, C - cnt);
		}
	}
	cout << result << "\n";
	return 0;
}