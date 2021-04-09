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
		if (ta != 0 && tb != b) { //a에서 b로
			int tmpw = min((b - tb), (ta)); //b의 남은공간과 a의 물의 양중 작은 것
			if(visitcheck[ta-tmpw][tb+tmpw][tc]==false) dfs(ta - tmpw, tb + tmpw, tc);
		}
		if (ta != 0 && tc != c) { //a에서 c로
			int tmpw = min((c- tc), (ta)); //b의 남은공간과 a의 물의 양중 작은 것
			if (visitcheck[ta - tmpw][tb][tc+tmpw] == false) dfs(ta - tmpw, tb, tc+tmpw);
		}
		if (tb != 0 && tc != c) {//b에서 c로
			int tmpw = min((c - tc), (tb)); 
			if (visitcheck[ta][tb - tmpw][tc+tmpw] == false) dfs(ta , tb-tmpw, tc + tmpw);
		}
		if (tb != 0 && ta != a) {//b에서 a로
			int tmpw = min((a - ta), (tb)); 
			if (visitcheck[ta + tmpw][tb - tmpw][tc] == false)dfs(ta + tmpw, tb - tmpw, tc);
		}
		if (tc != 0 && ta != a) {//c에서 a로
			int tmpw = min((a - ta), (tc));
			if (visitcheck[ta + tmpw][tb][tc-tmpw] == false)dfs(ta + tmpw, tb , tc - tmpw);
		}
		if (tc != 0 && tb != b) {//c에서 b로
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