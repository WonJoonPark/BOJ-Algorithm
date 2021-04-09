#include<bits/stdc++.h>
using namespace std;

long long n, m,tmp;
vector<long long> commitarr;
long long resulttime=1e18;
void inputs() {
	cin >> n >> m; //n���� �ɻ�� , m ���� ģ����
	for (int i = 0; i < n; i++) {
		cin >> tmp; commitarr.push_back(tmp);
	}
}

void findtime(long long l, long long h)
{
	if (l > h) return;
	long long mid = (l + h) / 2;
	long long tmpsum = 0;
	for (int i = 0; i < n; i++) {
		tmpsum += (mid / commitarr[i]); //�ð����� ������ �ɻ�뿡�� �ɻ簡���ο�
	}
	if (tmpsum >= m) {
		if (resulttime > mid) { resulttime = mid; } //�� �����ð����� �����ϸ� ����
		findtime(l, mid - 1);
	}
	else findtime(mid + 1, h);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	sort(commitarr.begin(), commitarr.end());
	long long lowtime = 1; long long hightime = commitarr[n - 1] * m;
	//���� �����ɸ��� �ɻ�뿡�� ��� ���� ��찡 �ִ�
	findtime(lowtime, hightime);
	cout << resulttime;
	return 0;
}