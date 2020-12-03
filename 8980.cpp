#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int boxinfo[2001][2001];
int N,C; //������ �� , Ʈ���� �뷮
int M; // �ڽ������� ��
int x, y, weight;
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> C;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> weight;
		boxinfo[x][y] = weight;
	}
	for (int i = 1; i <= N; i++) {
		//���ڳ�����
		for (int k = 1; k < i; k++) {
			C+=boxinfo[k][i];
		}
		if (C > 0) {
			for (int j = i + 1; j <= N; j++) { //���� �ø���
				if (C <= boxinfo[i][j]) {
					result += C; C = 0; break;
				}
				result += boxinfo[i][j];
				C -= boxinfo[i][j];
			}
		}
	}
	cout << result << "\n";
	return 0;
}