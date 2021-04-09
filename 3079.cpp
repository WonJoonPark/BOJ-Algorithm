#include<bits/stdc++.h>
using namespace std;

long long n, m,tmp;
vector<long long> commitarr;
long long resulttime=1e18;
void inputs() {
	cin >> n >> m; //n개의 심사대 , m 명의 친구들
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
		tmpsum += (mid / commitarr[i]); //시간동안 각각의 심사대에서 심사가능인원
	}
	if (tmpsum >= m) {
		if (resulttime > mid) { resulttime = mid; } //더 적은시간으로 가능하면 갱신
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
	//가장 오래걸리는 심사대에서 모두 받을 경우가 최대
	findtime(lowtime, hightime);
	cout << resulttime;
	return 0;
}