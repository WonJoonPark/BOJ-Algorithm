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
			if (inputs[i + 1] == 'P') { //PPAP�� �ϼ���
				pcount -= 1;
				i++;
			}
			else { cout << "NP"; return 0; } //A���� A�� ���� ���
		}
	}
	if (pcount == 1) cout << "PPAP"; 
	//PPAP�� ��� P�� ġȯ���ִ� �۾��� �ϱ� ������ �������� pcount=1
	else cout << "NP";

	return 0;
}

//PPAPPAPPAPPAP


//ġȯ���ִ� ����� �̿��� ��� �ð��ʰ� ���ɼ�

/*  <�ð��ʰ�> N*N 
while (1) {
	if (inputs == "PPAP") { cout << inputs; break; }
	if (inputs.length() <= 4) { cout << "NP"; break; }
	if (inputs.find("PPAP") == string::npos) { cout << "NP"; break; }
	inputs.replace(inputs.find("PPAP"), 4, "P");
}
*/