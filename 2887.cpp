#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int resultsum;

struct planet { int x, y, z,idx; };
struct edges { int cost, index1, index2; };

vector<planet> parr;
vector<int> rootindex;
vector<edges> earr;


bool cmp(edges a, edges b) {
	if (a.cost < b.cost) return true;
	else return false;
}
bool cmpx(planet a, planet b) {
	if (a.x < b.x) return true;
	else return false;
}
bool cmpy(planet a, planet b) {
	if (a.y < b.y) return true;
	else return false;
}
bool cmpz(planet a, planet b) {
	if (a.z < b.z) return true;
	else return false;
}

int minthree(int n1, int n2, int n3) {
	return min(min(n1, n2),n3);
}

void inputs() {
	cin >> N;
	int tmpx, tmpy, tmpz;
	planet tmpp;
	for (int i = 0; i < N; i++) { //정점삽입
		cin >> tmpx >> tmpy >> tmpz;
		tmpp.x = tmpx; tmpp.y = tmpy; tmpp.z = tmpz; tmpp.idx = i;
		parr.push_back(tmpp);
		rootindex.push_back(i); //처음에 루트는 각자 자기자신
	}
}
int find(int r) {
	if (rootindex[r] == r) return r;
	else { return rootindex[r] = find(rootindex[r]); }
}
void makeedges() { //간선 삽입
	edges tmpe;
	sort(parr.begin(), parr.end(), cmpx); //x 기준으로 오름차순 정렬
	for (int i = 0; i < N-1; i++) {
		tmpe.cost = abs(parr[i].x-parr[i + 1].x);
		tmpe.index1 = parr[i].idx; tmpe.index2 = parr[i + 1].idx;
		earr.push_back(tmpe);
	}
	sort(parr.begin(), parr.end(), cmpy); //y 기준으로 오름차순 정렬
	for (int i = 0; i < N - 1; i++) {
		tmpe.cost = abs(parr[i].y-parr[i + 1].y);
		tmpe.index1 = parr[i].idx; tmpe.index2 = parr[i + 1].idx;
		earr.push_back(tmpe);
	}
	sort(parr.begin(), parr.end(), cmpz); //z 기준으로 오름차순 정렬
	for (int i = 0; i < N - 1; i++) {
		tmpe.cost = abs(parr[i].z-parr[i + 1].z);
		tmpe.index1 = parr[i].idx; tmpe.index2 = parr[i + 1].idx;
		earr.push_back(tmpe);
	}
	sort(earr.begin(), earr.end(), cmp); //cost기준으로 오름차순 정렬
}
void makeMST() {
	int exitcount = 0;
	for (int i = 0; i < earr.size(); i++) {
		if (exitcount == N - 1) break;
		int firstplanet = find(earr[i].index1);
		int secondplanet = find(earr[i].index2);
		if (firstplanet == secondplanet) continue;
		rootindex[secondplanet] = firstplanet;
		resultsum += earr[i].cost;
		exitcount++;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	makeedges();
	makeMST();
	cout << resultsum;
	return 0;
}