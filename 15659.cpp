#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N,tmp;
vector<long long> numarr;
vector<long long> oper;
vector<long long> tmpoper;
long long maxresult = -9999999999;
long long minresult = 9999999999;
bool allplusorminus;

void inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> tmp; numarr.push_back(tmp); }
	for (int i = 0; i < 4; i++) { cin >> tmp; oper.push_back(tmp); }
}

int makenum() {
	vector<long long> tmparr;
	int index = 0;
	for (int i = 0; i < tmpoper.size(); i++) { //°ö¼À ³ª´°¼À ¸ÕÀú
		if (tmpoper[i] == 2 || tmpoper[i] == 3) {
			int tempint=numarr[index];
			while (1) { //¿¬¼ÓµÇ´Â °ö¼À,³ª´°¼À±îÁö´Â ¸ðµÎ °°ÀÌ Ã³¸®
				if (i == tmpoper.size() || tmpoper[i] == 0 || tmpoper[i] == 1) { index++; break; }
				if (tmpoper[i] == 2) { //°ö¼À
					tempint *= numarr[index + 1];
					index++;
				}
				else { //³ª´°¼À
					tempint /= numarr[index + 1];
					index++;
				}
				i++;
			}
			tmparr.push_back(tempint);
			i--;
		}
		else { //¾Æ·¡¿Í °°ÀÌ »ý°¢ÇØÁà¾ßÇÒ ¿¹¿Ü»çÇ×ÀÌ ³Ê¹« ¸¹´Ù.!!!!!!!!!!!!!!!
			if (i==0 || i == tmpoper.size() - 1){ 
				tmparr.push_back(numarr[index]); index++;
				if (tmpoper.size() == 1) tmparr.push_back(numarr[index]);
			}
			if (i < tmpoper.size() - 1 && (tmpoper[i + 1] == 0 || tmpoper[i + 1] == 1)) { 
				tmparr.push_back(numarr[index]);
				index++;
			}
		}
	}
	long long result=tmparr[0];
	index = 1;
	for (int i = 0; i < tmpoper.size(); i++) {
		if (tmpoper[i] == 0 || tmpoper[i] == 1) {
			if (tmpoper[i] == 0) { // µ¡¼À
				result += tmparr[index];
				index++;
			}
			else { //»¬¼À
				result -= tmparr[index];
				index++;
			}
		}
	}
	return result;
}

void makecase(int cnt) {
	if (cnt == N - 1) {
		/*cout << numarr[0];
		for (int i = 0; i < tmpoper.size(); i++) {
			if (tmpoper[i] == 0) { cout << " + "; }
			if (tmpoper[i] == 1) { cout << " - "; }
			if (tmpoper[i] == 2) { cout << " * "; }
			if (tmpoper[i] == 3) { cout << " / "; }
			cout << numarr[i + 1];
		}
		cout << "\n";*/
		if (makenum() > maxresult) { maxresult = makenum(); }
		if (makenum() < minresult) { minresult = makenum(); }
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			tmpoper.push_back(i);
			oper[i]--;
			makecase(cnt + 1);
			oper[i]++;
			tmpoper.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	makecase(0);
	cout << maxresult << "\n" << minresult << "\n";
	return 0;
}