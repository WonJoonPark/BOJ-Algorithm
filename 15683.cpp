#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, M;
int cctvmap[8][8];
struct cctv {
	int x; int y; int num;
};
vector<cctv> carr;
int dx[4] = { -1,0,1,0 }; //북동남서
int dy[4] = { 0,1,0,-1 };

void inputs() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cctvmap[i][j];
			if (cctvmap[i][j] == 6) continue;
			else if (cctvmap[i][j] == 0) continue;
			else { //1,2,3,4,5
				cctv tc; tc.x = i; tc.y = j; tc.num = cctvmap[i][j];
				carr.push_back(tc);
			}
		}
	}
}
int minresult = 64;

void countzero() {
	int resultzero = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cctvmap[i][j] == 0) resultzero++;
		}
	}
	if (resultzero < minresult) minresult = resultzero;
}

void findzero(int countcctv) {
	if (countcctv == carr.size()) {
		countzero();
		 return;
	}
	for (int i = countcctv; i < carr.size(); i++) {
		if(carr[i].num==1){
			for (int j = 0; j < 4; j++) {
				vector<pair<int, int>> tmpvector;
				int tmpx = carr[i].x; int tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M||cctvmap[tmpx][tmpy]==6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[j]; tmpy += dy[j]; //그 방향으로 계속 전진
				}
				findzero(i + 1);
				for (int k = 0; k < tmpvector.size(); k++) { //다시 맵을 원상태로
					cctvmap[tmpvector[k].first][tmpvector[k].second] = 0;
				}
				tmpvector.clear();
			}
		}
		else if (carr[i].num == 2) {
			for (int j = 0; j < 2; j++) {
				vector<pair<int, int>> tmpvector;
				int tmpx = carr[i].x; int tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[j]; tmpy += dy[j]; //그 방향으로 계속 전진
				}
				tmpx = carr[i].x; tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[j+2]; tmpy += dy[j+2]; //그 방향으로 계속 전진
				}
				findzero(i + 1);
				for (int k = 0; k < tmpvector.size(); k++) { //다시 맵을 원상태로
					cctvmap[tmpvector[k].first][tmpvector[k].second] = 0;
				}
				tmpvector.clear();
				}
			}
		else if(carr[i].num==3){
			for (int j = 0; j < 4; j++) {
				vector<pair<int, int>> tmpvector;
				int tmpx = carr[i].x; int tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[j]; tmpy += dy[j]; //그 방향으로 계속 전진
				}
				tmpx = carr[i].x; tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[(j+1)%4]; tmpy += dy[(j+1)%4]; //그 방향으로 계속 전진

				}
				findzero(i+ 1);
				for (int k = 0; k < tmpvector.size(); k++) { //다시 맵을 원상태로
					cctvmap[tmpvector[k].first][tmpvector[k].second] = 0;
				}
				tmpvector.clear();
			}
		}
		else if(carr[i].num==4){
			for (int j = 0; j < 4; j++) {
				vector<pair<int, int>> tmpvector;
				int tmpx = carr[i].x; int tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[j]; tmpy += dy[j]; //그 방향으로 계속 전진

				}
				 tmpx = carr[i].x;tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[(j+1)%4]; tmpy += dy[(j+1)%4]; //그 방향으로 계속 전진

				}
				 tmpx = carr[i].x; tmpy = carr[i].y;
				while (1) {
					if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
					if (cctvmap[tmpx][tmpy] == 0) {
						cctvmap[tmpx][tmpy] = 7;
						pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
						tmpvector.push_back(tmpp);
					}
					tmpx += dx[(j + 2) % 4]; tmpy += dy[(j + 2) % 4]; //그 방향으로 계속 전진

				}
				findzero(i + 1);
				for (int k = 0; k < tmpvector.size(); k++) { //다시 맵을 원상태로
					cctvmap[tmpvector[k].first][tmpvector[k].second] = 0;
				}
				tmpvector.clear();
			}
		}
		else { //5
		vector<pair<int, int>> tmpvector;
		int tmpx = carr[i].x; int tmpy = carr[i].y;
		while (1) {
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
			if (cctvmap[tmpx][tmpy] == 0) {
				cctvmap[tmpx][tmpy] = 7;
				pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
				tmpvector.push_back(tmpp);
			}
			tmpx += dx[0]; tmpy += dy[0]; //그 방향으로 계속 전진

		}
		tmpx = carr[i].x; tmpy = carr[i].y;
		while (1) {
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
			if (cctvmap[tmpx][tmpy] == 0) {
				cctvmap[tmpx][tmpy] = 7;
				pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
				tmpvector.push_back(tmpp);
			}
			tmpx += dx[1]; tmpy += dy[1]; //그 방향으로 계속 전진

		}
		tmpx = carr[i].x; tmpy = carr[i].y;
		while (1) {
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
			if (cctvmap[tmpx][tmpy] == 0) {
				cctvmap[tmpx][tmpy] = 7;
				pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
				tmpvector.push_back(tmpp);
			}
			tmpx += dx[2]; tmpy += dy[2]; //그 방향으로 계속 전진

		}
		tmpx = carr[i].x;tmpy = carr[i].y;
		while (1) {
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M || cctvmap[tmpx][tmpy] == 6) { break; } //범위를 넘거나 벽이거나
			if (cctvmap[tmpx][tmpy] == 0) {
				cctvmap[tmpx][tmpy] = 7;
				pair<int, int> tmpp; tmpp.first = tmpx; tmpp.second = tmpy;
				tmpvector.push_back(tmpp);
			}
			tmpx += dx[3]; tmpy += dy[3]; //그 방향으로 계속 전진
		}
		findzero(i + 1);
		for (int k = 0; k < tmpvector.size(); k++) { //다시 맵을 원상태로
			cctvmap[tmpvector[k].first][tmpvector[k].second] = 0;
		}
		tmpvector.clear();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	findzero(0);
	cout << minresult << "\n";
	return 0;
}