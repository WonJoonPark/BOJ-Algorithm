#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int N, M, K;
int x, y;
int jido[21][21];
int dice[7]; //주사위 (1~6면) //윗면이 무조건 dice[1] ,아랫면이 dice[6]
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

void movedice(int c) {
	if(c==1){ //동
		int tmpdice[7];
		tmpdice[6] = dice[3]; tmpdice[3] = dice[1];
		tmpdice[4] = dice[6]; tmpdice[1] = dice[4];
		tmpdice[5] = dice[5]; tmpdice[2] = dice[2];
		for (int i = 1; i < 7; i++) dice[i] = tmpdice[i];
	}
	if(c==2){
		int tmpdice[7];
		tmpdice[6] = dice[4]; tmpdice[3] = dice[6];
		tmpdice[4] = dice[1]; tmpdice[1] = dice[3];
		tmpdice[5] = dice[5]; tmpdice[2] = dice[2];
		for (int i = 1; i < 7; i++) dice[i] = tmpdice[i];
	}
	if (c == 3){
		int tmpdice[7];
		tmpdice[6] = dice[2]; tmpdice[2] = dice[1];
		tmpdice[5] = dice[6]; tmpdice[1] = dice[5];
		tmpdice[3] = dice[3]; tmpdice[4] = dice[4];
		for (int i = 1; i < 7; i++) dice[i] = tmpdice[i];
	}
	if (c == 4) {
		int tmpdice[7];
		tmpdice[6] = dice[5]; tmpdice[2] = dice[6];
		tmpdice[5] = dice[1]; tmpdice[1] = dice[2];
		tmpdice[3] = dice[3]; tmpdice[4] = dice[4];
		for (int i = 1; i < 7; i++) dice[i] = tmpdice[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >>x>>y>>K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> jido[i][j];
		}
	}
	int command;
	for (int i = 0; i < K; i++) {
		cin >> command;
		if (x + dx[command] < 0 || x + dx[command] >= N || y + dy[command] < 0 || y + dy[command] >= M) continue;
		movedice(command);
		if (jido[x + dx[command]][y + dy[command]] == 0) {
			jido[x + dx[command]][y + dy[command]] = dice[6];
		}
		else {
			dice[6] = jido[x + dx[command]][y + dy[command]];
			jido[x + dx[command]][y + dy[command]] = 0;
		}
		x += dx[command]; y += dy[command];
		cout << dice[1] << "\n";
	}
	return 0;
}