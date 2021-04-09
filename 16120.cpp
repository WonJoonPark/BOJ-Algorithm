#include<bits/stdc++.h>
using namespace std;

string inputs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> inputs;
	int pcount = 0;
	for (int i = 0; i < inputs.length(); i++) {
		if (inputs[i] == 'P') {
			pcount++;
		}
		else { // A
			if (pcount < 2) { cout << "NP"; return 0; }
			if (inputs[i + 1] == 'P') { //PPAP가 완성됨
				pcount -= 1;
				i++;
			}
			else { cout << "NP"; return 0; } //A다음 A가 오는 경우
		}
	}
	if (pcount == 1) cout << "PPAP"; 
	//PPAP를 계속 P로 치환해주는 작업을 하기 때문에 마지막엔 pcount=1
	else cout << "NP";

	return 0;
}

//PPAPPAPPAPPAP


//치환해주는 방식을 이용할 경우 시간초과 가능성

/*  <시간초과> N*N 
while (1) {
	if (inputs == "PPAP") { cout << inputs; break; }
	if (inputs.length() <= 4) { cout << "NP"; break; }
	if (inputs.find("PPAP") == string::npos) { cout << "NP"; break; }
	inputs.replace(inputs.find("PPAP"), 4, "P");
}
*/