#include<bits/stdc++.h>
using namespace std;

int a, b, c;
bool already[201];
bool visitcheck[201][201][201];
vector<int> resultarr;

struct waterball {
	int ax, bx, cx;
};

void dfs(int ta, int tb, int tc) {
		visitcheck[ta][tb][tc] = true;
		if (ta==0) {
			if (already[tc] == false) {
				resultarr.push_back(tc);
				already[tc] = true;
			}
		}
		if (ta != 0 && tb != b) { //a���� b��
			int tmpw = min((b - tb), (ta)); //b�� ���������� a�� ���� ���� ���� ��
			if(visitcheck[ta-tmpw][tb+tmpw][tc]==false) dfs(ta - tmpw, tb + tmpw, tc);
		}
		if (ta != 0 && tc != c) { //a���� c��
			int tmpw = min((c- tc), (ta)); //b�� ���������� a�� ���� ���� ���� ��
			if (visitcheck[ta - tmpw][tb][tc+tmpw] == false) dfs(ta - tmpw, tb, tc+tmpw);
		}
		if (tb != 0 && tc != c) {//b���� c��
			int tmpw = min((c - tc), (tb)); 
			if (visitcheck[ta][tb - tmpw][tc+tmpw] == false) dfs(ta , tb-tmpw, tc + tmpw);
		}
		if (tb != 0 && ta != a) {//b���� a��
			int tmpw = min((a - ta), (tb)); 
			if (visitcheck[ta + tmpw][tb - tmpw][tc] == false)dfs(ta + tmpw, tb - tmpw, tc);
		}
		if (tc != 0 && ta != a) {//c���� a��
			int tmpw = min((a - ta), (tc));
			if (visitcheck[ta + tmpw][tb][tc-tmpw] == false)dfs(ta + tmpw, tb , tc - tmpw);
		}
		if (tc != 0 && tb != b) {//c���� b��
			int tmpw = min((b - tb), (tc));
			if (visitcheck[ta][tb + tmpw][tc-tmpw] == false)dfs(ta, tb + tmpw, tc - tmpw);
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	dfs(0, 0, c);
	sort(resultarr.begin(), resultarr.end());
	for (int i = 0; i < resultarr.size(); i++) {
		cout << resultarr[i] << " ";
	}
	return 0;
}